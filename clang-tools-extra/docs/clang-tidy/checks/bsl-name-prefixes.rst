.. title:: clang-tidy - bsl-name-prefixes

bsl-name-prefixes
=================

Variables names must conform for the following rules:
- All global variables start with 'g_'
- All static local/member variables must start with 's_'
- All member variables must start with 'm_'

Variables marked as 'constexpr" do not need to follow this rule, and member
variables of structs also do not need to follow this rule.
