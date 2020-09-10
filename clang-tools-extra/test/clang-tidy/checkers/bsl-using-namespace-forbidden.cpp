// RUN: %check_clang_tidy %s bsl-using-namespace-forbidden %t

namespace bsl
{}

namespace
{}

using namespace bsl;
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: using directives are forbidden [bsl-using-namespace-forbidden]
