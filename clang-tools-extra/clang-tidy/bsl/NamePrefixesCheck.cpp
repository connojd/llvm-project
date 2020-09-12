//===--- NamePrefixesCheck.cpp - clang-tidy -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "NamePrefixesCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace bsl {

void NamePrefixesCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
    declaratorDecl(
      unless(
        anyOf(
          isImplicit(),
          isExpansionInSystemHeader()
        )
      )
    ).bind("decl"),
    this
  );
}

bool
startsWith(std::string const &str, const char *prefix)
{
  if (str.size() < 2)
    return false;

  if (str[0] != prefix[0] || str[1] != prefix[1])
    return false;

  return true;
}

void NamePrefixesCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *DD = Result.Nodes.getNodeAs<DeclaratorDecl>("decl");
  auto const name{DD->getNameAsString()};

  if (const auto *VD = dyn_cast<VarDecl>(DD)) {
    // Ignore constexpr variables
    if (VD->isConstexpr()) {
      return;
    }

    if (VD->isStaticLocal() || VD->isStaticDataMember()) {
      if (!startsWith(name, "s_")) {
        diag(VD->getLocation(), "static local/member variables must start with 's_'");
      }

      return;
    }

    if (!VD->isLocalVarDeclOrParm()) {
      if (!startsWith(name, "g_")) {
        diag(VD->getLocation(), "global variables must start with 'g_'");
      }

      return;
    }
  }

  if (const auto *FD = dyn_cast<FieldDecl>(DD)) {
    // Ignore structs
    if (const auto *CXXRD = dyn_cast<CXXRecordDecl>(FD->getParent())) {
      if (CXXRD->isStruct()) {
        return;
      }
    }

    if (!startsWith(name, "m_")) {
      diag(FD->getLocation(), "non-static member variables must start with 'm_'");
    }

    return;
  }
}

} // namespace bsl
} // namespace tidy
} // namespace clang
