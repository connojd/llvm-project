//===--- EmptyIfElseCheck.cpp - clang-tidy --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "EmptyIfElseCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace bsl {

void EmptyIfElseCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
    compoundStmt(
      forEach(
        ifStmt(
          stmt(),
          unless(isConstexpr())
        ).bind("if")
      )
    ),
    this);
}

void EmptyIfElseCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *IF = Result.Nodes.getNodeAs<IfStmt>("if");

  if (IF->getThen()) {
    if (IF->getThen()->children().empty()) {
      diag(IF->getIfLoc(), "Empty 'if' statements are forbidden");
    }
  }

  if (IF->getElse()) {
    if (IF->getElse()->children().empty()) {
      diag(IF->getElseLoc(), "Empty 'else' statements are forbidden");
    }
  }
}

} // namespace bsl
} // namespace tidy
} // namespace clang
