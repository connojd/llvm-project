.. title:: clang-tidy - bsl-empty-if-else

bsl-empty-if-else
=================

All if, else-if and else statements must not be empty. If it needs to be
empty, add a call to bsl::touch() to indicate there is nothing to do.
