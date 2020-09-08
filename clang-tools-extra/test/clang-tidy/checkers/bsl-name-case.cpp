// RUN: %check_clang_tidy %s bsl-name-case %t

int global_var1{};
constexpr int global_var2{};
// CHECK-MESSAGES: :[[@LINE-1]]:15: warning: name of global constexpr is not in upper case [bsl-name-case]

template<typename T>
using alias1 = int;
template<typename t>
// CHECK-MESSAGES: :[[@LINE-1]]:19: warning: name of template variable is not in upper case [bsl-name-case]
using alias2 = int;

void function_with_static_local_var()
{
    static int static_var{};
}

class class_with_static_data_member
{
public:
    static int static_member_var;
};

int class_with_static_data_member::static_member_var{};
