//===--- DependentBaseNameCheck.cpp - clang-tidy --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "DependentBaseNameCheck.h"
#include "BslCheckUtils.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclLookups.h"
#include "clang/AST/DeclTemplate.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Lex/Lexer.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace bsl {

struct LookupEntry {
    const NamedDecl *FoundName;
    DeclContext *FoundContext;
};

AST_MATCHER(CXXRecordDecl, hasAnyDependentBases) {
  return Node.hasAnyDependentBases();
}

AST_MATCHER(DeclRefExpr, isDependent) {
  return Node.isTypeDependent() || Node.isValueDependent() ||
         Node.isInstantiationDependent();
}

AST_MATCHER(DeclRefExpr, hasQualifier) {
  return Node.hasQualifier();
}

AST_MATCHER(DeclaratorDecl, isVarTemplateSpecialization) {
  return isa<VarTemplateSpecializationDecl>(Node);
}

static inline bool isIdentifierChar(char c)
{
  return (c >= '0' && c <= '9') ||
         (c >= 'A' && c <= 'Z') ||
         (c >= 'a' && c <= 'z') ||
         c == '_';
}

static inline bool typeHasSugar(const QualType &QT, const ASTContext &Context)
{
  const auto UT = QT.getUnqualifiedType();
  return UT.getSingleStepDesugaredType(Context) != UT;
}

static inline bool textHasScopeResolution(const StringRef &Text)
{
  return Text.contains("::");
}

static inline StringRef sourceRangeToText(const SourceRange Range,
                                          const SourceManager &SM,
                                          const LangOptions &LangOpts,
                                          bool *Invalid)
{
    if (Range.isInvalid()) {
      *Invalid = true;
      return StringRef();
    }

    const auto CharRange = clang::Lexer::getAsCharRange(Range, SM, LangOpts);
    const auto Text = clang::Lexer::getSourceText(CharRange, SM, LangOpts,
                                                  Invalid);
    if (*Invalid)
      return StringRef();

    return Text;
}

static inline StringRef sourceTextToName(const StringRef &Text)
{
  const auto BackText = Text.drop_until([](char c){ return isIdentifierChar(c); });
  return BackText.take_while([](char c){ return isIdentifierChar(c); });
}

static bool lookupInDeclContext(const StringRef &Name,
                                struct LookupEntry *Entry)
{
  if (!Entry->FoundContext)
    return false;

  const NamedDecl *FoundName = nullptr;
  DeclContext *Context = Entry->FoundContext;

  while (!FoundName && Context) {
    for (DeclContextLookupResult LookupResult : Context->lookups()) {
      for (const auto *ND : LookupResult) {
        if (!ND->getDeclName().isIdentifier())
          continue;

        if (ND->getName().equals(Name)) {
          FoundName = ND;
          break;
        }
      }

      if (FoundName)
        break;
    }

    if (!FoundName)
      Context = Context->getLookupParent();
  }

  Entry->FoundName = FoundName;
  Entry->FoundContext = Context;

  return FoundName != nullptr;
}

static bool lookupInBaseClasses(
  const MatchFinder::MatchResult &Result,
  const DeclarationName &Name,
  DeclContext *FoundContext,
  std::vector<const NamedDecl *> &BaseNames)
{
  if (!FoundContext)
    return false;

  auto *Record = const_cast<CXXRecordDecl *>(
      Result.Nodes.getNodeAs<CXXRecordDecl>("record"));

  if (!FoundContext->Encloses(Record) || FoundContext->Equals(Record))
    return false;

  BaseNames = Record->lookupDependentName(
                Name,
                [](const NamedDecl *){ return true; }
              );

  return !BaseNames.empty();
}

void DependentBaseNameCheck::checkDeclRef(
  const MatchFinder::MatchResult &Result,
  const DeclRefExpr *DeclRef)
{
  const auto Name = DeclRef->getNameInfo().getName();
  const auto VD = DeclRef->getDecl();

  if (!VD)
    return;

  // Get the DeclContext in which the original ValueDecl the DeclRef
  // refers to is found
  auto *FoundContext = const_cast<DeclContext *>(VD->getDeclContext());
  std::vector<const NamedDecl *> BaseNames;

  if (!lookupInBaseClasses(Result, Name, FoundContext, BaseNames))
    return;

  diag(DeclRef->getExprLoc(),
       "multiple declarations with name %0 found; need to qualify %0 used "
       "here") << Name;
  diag(VD->getLocation(), "using the declaration of %0 "
       "found here", DiagnosticIDs::Note) << Name;
  diag(BaseNames[0]->getLocation(), "but also found declaration of %0 "
       "in base class here", DiagnosticIDs::Note) << Name;

  return;
}

void DependentBaseNameCheck::checkDeclarator(
  const MatchFinder::MatchResult &Result,
  const DeclaratorDecl *Decl)
{
  const auto *TypeSrc = Decl->getTypeSourceInfo();

  if (!TypeSrc)
    return;

  const auto QT = TypeSrc->getType();
  const auto BaseTypeID = QT.getBaseTypeIdentifier();

  if (!BaseTypeID) {
    return;
  }

  const auto Name = BaseTypeID->getName();
  LookupEntry Entry{nullptr,
                    const_cast<DeclContext *>(Decl->getDeclContext())};

  if (!lookupInDeclContext(Name, &Entry))
    return;

  auto FoundName = Entry.FoundName->getDeclName();
  auto FoundContext = Entry.FoundContext;
  std::vector<const NamedDecl *> BaseNames;

  if (!lookupInBaseClasses(Result, FoundName, FoundContext, BaseNames))
    return;

  const auto BaseName = BaseNames[0];

  diag(Decl->getTypeSpecStartLoc(),
       "multiple declarations with name '%0' found; need to qualify '%0' "
       "used here") << Name;
  diag(Entry.FoundName->getLocation(), "using the declaration of '%0' found "
       " here", DiagnosticIDs::Note) << Name;
  diag(BaseName->getLocation(),
       "but also found declaration of '%0' in base class here",
       DiagnosticIDs::Note) << Name;

  return;
}

void DependentBaseNameCheck::checkMethod(
  const MatchFinder::MatchResult &Result,
  const CXXMethodDecl *Method)
{
  const auto RT = Method->getDeclaredReturnType();
  const auto BaseID = RT.getBaseTypeIdentifier();

  if (!BaseID) {
    return;
  }

  const auto Name = BaseID->getName();
  LookupEntry Entry{nullptr, const_cast<DeclContext *>(Method->getLookupParent())};

  if (!lookupInDeclContext(Name, &Entry))
    return;

  auto FoundName = Entry.FoundName->getDeclName();
  auto FoundContext = Entry.FoundContext;
  std::vector<const NamedDecl *> BaseNames;

  if (!lookupInBaseClasses(Result, FoundName, FoundContext, BaseNames))
    return;

  const auto BaseName = BaseNames[0];

  diag(Method->getReturnTypeSourceRange().getBegin(),
       "multiple declarations with name '%0' found; need to qualify the "
       "name here") << Name;
  diag(Entry.FoundName->getLocation(), "using the declaration of '%0' found here",
       DiagnosticIDs::Note) << Name;
  diag(BaseName->getLocation(),
       "but also found declaration of '%0' in base class here",
       DiagnosticIDs::Note) << Name;

  return;
}

void DependentBaseNameCheck::checkTypedefName(
  const MatchFinder::MatchResult &Result,
  const TypedefNameDecl *TypedefName)
{
  const auto QT = TypedefName->getUnderlyingType();
  const auto BaseID = QT.getBaseTypeIdentifier();

  if (!BaseID) {
    return;
  }

  const auto Name = BaseID->getName();
  LookupEntry Entry{nullptr,
                    const_cast<DeclContext *>(TypedefName->getDeclContext())};

  if (!lookupInDeclContext(Name, &Entry))
    return;

  auto FoundName = Entry.FoundName->getDeclName();
  auto FoundContext = Entry.FoundContext;
  std::vector<const NamedDecl *> BaseNames;

  if (!lookupInBaseClasses(Result, FoundName, FoundContext, BaseNames))
    return;

  const auto BaseName = BaseNames[0];

  diag(TypedefName->getLocation(),
       "multiple declarations with name '%0' found; need to qualify the "
       "name here") << Name;
  diag(Entry.FoundName->getLocation(), "using the declaration of '%0' found here",
       DiagnosticIDs::Note) << Name;

  //TODO: loop through each found name
  diag(BaseName->getLocation(),
       "but also found declaration of '%0' in base class here",
       DiagnosticIDs::Note) << Name;

  return;
}

void DependentBaseNameCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
      declRefExpr(
          hasAncestor(cxxRecordDecl(hasAnyDependentBases(),
                                    hasParent(classTemplateDecl())
                                   ).bind("record")),
          unless(anyOf(isDependent(), hasQualifier()))).bind("decl-ref"),
      this);

  Finder->addMatcher(
      cxxMethodDecl(
          hasParent(cxxRecordDecl(hasAnyDependentBases(),
                                  hasParent(classTemplateDecl())
                                 ).bind("record")),
          unless(anyOf(isImplicit(),
                       isCopyAssignmentOperator(),
                       isMoveAssignmentOperator(),
                       cxxConstructorDecl(),
                       cxxDestructorDecl()))).bind("method"),
      this);

  Finder->addMatcher(
      declaratorDecl(anyOf(varDecl(), fieldDecl(), nonTypeTemplateParmDecl()),
           hasAncestor(cxxRecordDecl(hasAnyDependentBases(),
                                     hasParent(classTemplateDecl())
                                    ).bind("record")),
           unless(anyOf(isImplicit(), isVarTemplateSpecialization()))
          ).bind("decl-decl"),
      this);

  Finder->addMatcher(
      typedefNameDecl(hasAncestor(cxxRecordDecl(hasAnyDependentBases(),
                                                hasParent(classTemplateDecl())
                                               ).bind("record"))
                     ).bind("typedef-name"),
      this);
}

void DependentBaseNameCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *DeclRef = Result.Nodes.getNodeAs<DeclRefExpr>("decl-ref");
  if (DeclRef) {
    checkDeclRef(Result, DeclRef);
    return;
  }

  const auto *Method = Result.Nodes.getNodeAs<CXXMethodDecl>("method");
  if (Method) {
    checkMethod(Result, Method);
    return;
  }

  const auto *DeclDecl = Result.Nodes.getNodeAs<DeclaratorDecl>("decl-decl");
  if (DeclDecl) {
    checkDeclarator(Result, DeclDecl);
    return;
  }

  const auto *TypedefName = Result.Nodes.getNodeAs<TypedefNameDecl>("typedef-name");
  if (TypedefName) {
    checkTypedefName(Result, TypedefName);
    return;
  }

}

} // namespace bsl
} // namespace tidy
} // namespace clang
