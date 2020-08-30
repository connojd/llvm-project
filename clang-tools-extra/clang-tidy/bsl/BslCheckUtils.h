//===--- BslCheckUtils.h - clang-tidy-------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BSL_CHECK_UTILS_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BSL_CHECK_UTILS_H

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Lex/Token.h"

namespace clang {
namespace tidy {
namespace bsl {

// Returns the StringRef of the raw Token at the given SourceLocation
StringRef getRawTokenStr(SourceLocation Loc,
                         const ast_matchers::MatchFinder::MatchResult &Result);

Token getTokenAtLoc(SourceLocation Loc,
                    const ast_matchers::MatchFinder::MatchResult &MatchResult,
                    IdentifierTable &IdentTable);

} // namespace bsl
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BSL_CHECK_UTILS_H
