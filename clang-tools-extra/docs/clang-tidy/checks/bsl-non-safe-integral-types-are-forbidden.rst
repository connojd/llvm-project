.. title:: clang-tidy - bsl-non-safe-integral-types-are-forbidden

bsl-non-safe-integral-types-are-forbidden
=========================================

Integral types are not allowed. Instead of using int, std::int32_t, bsl::int32,
or any other types like this, use bsl::safe_integral instead. Booleans and
char types (not unsigned/signed char types, just char) are allowed.
