// RUN: %check_clang_tidy %s bsl-name-prefixes %t

constexpr int global_var1 = 42;
int global_var2 = 42;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: global variables must start with 'g_' [bsl-name-prefixes]
int g_global_var3 = 42;

namespace namespaceWithGlobalVariables
{
    constexpr int global_var1 = 42;
    int global_var2 = 42;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: global variables must start with 'g_' [bsl-name-prefixes]
    int g_global_var3 = 42;
}

void
functionWithStaticLocal()
{
    constexpr static int static_var1 = 42;
    static int static_var2 = 42;
    // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: static local/member variables must start with 's_' [bsl-name-prefixes]
    static int s_static_var3 = 42;
}

class classWithStaticLocalsAndMembers
{
    constexpr static int static_var1 = 42;
    static int static_var2;
    // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: static local/member variables must start with 's_' [bsl-name-prefixes]
    static int s_static_var3;

    void
    memberFunctionWithStaticLocal()
    {
        constexpr static int static_var1 = 42;
        static int static_var2 = 42;
        // CHECK-MESSAGES: :[[@LINE-1]]:20: warning: static local/member variables must start with 's_' [bsl-name-prefixes]
        static int s_static_var3 = 42;
    }
};

class classMembers
{
    int member_var1;
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: non-static member variables must start with 'm_' [bsl-name-prefixes]
    int m_member_var2;
};

struct structMembers
{
    int member_var1;
};
