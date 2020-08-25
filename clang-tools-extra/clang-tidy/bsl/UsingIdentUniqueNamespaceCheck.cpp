//===--- UsingIdentUniqueNamespaceCheck.cpp - clang-tidy ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "UsingIdentUniqueNamespaceCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace bsl {

static std::string getNestedNameSpecifierAsString(NamedDecl const *D) {
  std::string name;
  llvm::raw_string_ostream OStream{name};

  D->printNestedNameSpecifier(OStream);
  OStream.flush();

  return name;
}

void UsingIdentUniqueNamespaceCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
    namedDecl(
      unless(
        isImplicit()
      )
    ).bind("decl"),
    this
  );
}

void UsingIdentUniqueNamespaceCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *D = Result.Nodes.getNodeAs<NamedDecl>("decl");
  const auto Loc = D->getLocation();

  if (isa<VarDecl>(D) ||
      isa<ParmVarDecl>(D) ||
      isa<CXXConstructorDecl>(D) ||
      isa<CXXDestructorDecl>(D) ||
      isa<VarTemplateDecl>(D) ||
      isa<TemplateTypeParmDecl>(D) ||
      isa<NonTypeTemplateParmDecl>(D) ||
      isa<TemplateTemplateParmDecl>(D) ||
      isa<TypeAliasTemplateDecl>(D) ||
      isa<ClassTemplateDecl>(D) ||
      isa<ClassTemplateSpecializationDecl>(D)) {
    return;
  }

  if (Loc.isInvalid())
    return;

  if (D->getParentFunctionOrMethod() != nullptr)
    return;

  auto Name{D->getNameAsString()};
  auto Spec{getNestedNameSpecifierAsString(D)};

  if (Name.empty() || Name[0] == '_')
    return;

  if (isa<FunctionDecl>(D)) {
    const auto FD{cast<FunctionDecl>(D)};
    if (FD->isOverloadedOperator())
      return;
  }

  if (isa<FunctionTemplateDecl>(D)) {
    const auto FTD{cast<FunctionTemplateDecl>(D)};
    if (isa<CXXConstructorDecl>(FTD->getTemplatedDecl()))
      return;
  }

  auto iter{m_ids.find(Name)};
  if (iter != m_ids.end()) {
    auto &recordList{iter->second};
    for (auto const &record : recordList) {
      if (Spec == record.spec) {
        continue;
      }

      if (Spec.find(record.spec) != std::string::npos) {
        diag(Loc, "A user-defined type name shall be a unique identifier within a namespace");
        diag(record.loc, "previous user-defined with the same name found here", DiagnosticIDs::Note);
        return;
      }

      if (record.spec.find(Spec) != std::string::npos) {
        diag(Loc, "A user-defined type name shall be a unique identifier within a namespace");
        diag(record.loc, "previous user-defined with the same name found here", DiagnosticIDs::Note);
        return;
      }
    }
  }

  if (isa<NamespaceDecl>(D))
    return;

  m_ids[Name].push_back({Spec, Loc});
}

} // namespace bsl
} // namespace tidy
} // namespace clang
