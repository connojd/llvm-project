//===--- DependentBaseNameCheck.h - clang-tidy ------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BSL_DEPENDENTBASENAMECHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BSL_DEPENDENTBASENAMECHECK_H

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace bsl {

/// Checks that names in a class template found in its dependent base are
/// referred to using a qualified-id or this
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/bsl-dependent-base-name.html
class DependentBaseNameCheck : public ClangTidyCheck {
public:
  DependentBaseNameCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
  bool isLanguageVersionSupported(const LangOptions &LangOpts) const override {
    return LangOpts.CPlusPlus;
  }

private:
  void checkDeclRef(const ast_matchers::MatchFinder::MatchResult &Result,
                    const DeclRefExpr *DeclRef);
  void checkMethod(const ast_matchers::MatchFinder::MatchResult &Result,
                   const CXXMethodDecl *Method);
  void checkDeclarator(const ast_matchers::MatchFinder::MatchResult &Result,
                       const DeclaratorDecl *DeclDecl);
  void checkTypedefName(const ast_matchers::MatchFinder::MatchResult &Result,
                        const TypedefNameDecl *TypedefName);
};

} // namespace bsl
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BSL_DEPENDENTBASENAMECHECK_H
