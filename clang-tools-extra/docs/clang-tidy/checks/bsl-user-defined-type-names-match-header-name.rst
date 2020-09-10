.. title:: clang-tidy - bsl-user-defined-type-names-match-header-name

bsl-user-defined-type-names-match-header-name
=============================================

The name of a user defined type must match the header name it is defined in.
For example, if we create a class called "myclass", the header file it is
defined in must be named "myclass.h" or "myclass.hpp", regardless of the
namespace the class is defined in. 
