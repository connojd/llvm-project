// RUN: %check_clang_tidy %s bsl-empty-if-else %t

void foo()
{
    int var;

    if (42 == 42) {
        var = 42;
    }
    else {
        var = 42;
    }

    if (42 == 42) {
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Empty 'if' statements are forbidden [bsl-empty-if-else]
    }
    else {
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: Empty 'else' statements are forbidden [bsl-empty-if-else]
    }

    if constexpr (42 == 42) {
    }
}


