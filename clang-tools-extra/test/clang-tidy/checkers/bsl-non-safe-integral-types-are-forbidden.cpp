// RUN: %check_clang_tidy %s bsl-non-safe-integral-types-are-forbidden %t

int i1;
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: integral types like int, std::int32_t and bsl::int32 are forbidden. Use bsl::safe_integral instead of int [bsl-non-safe-integral-types-are-forbidden]

using myint = int;
myint i2;
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: integral types like int, std::int32_t and bsl::int32 are forbidden. Use bsl::safe_integral instead of int [bsl-non-safe-integral-types-are-forbidden]

bool ok1;
char ok2;
