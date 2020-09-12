// RUN: %check_clang_tidy %s bsl-documentation %t

template<typename T1, typename T2, int T4, int T5>
int function1(int var1, int var2);

/// @brief comment
/// @param var1 comment
/// @param var3 comment
/// @tparam T1 comment
/// @tparam T3 comment
/// @tparam T4 comment
template<typename T1, typename T2, int T4, int T5>
int function2(int var1, int var2);
// CHECK-MESSAGES: :[[@LINE-2]]:5: warning: Documented parameter does not exist [bsl-documentation]

class class1
{};

/// @brief comment
/// @tparam T1 comment
/// @tparam T3 comment
/// @tparam T4 comment
template<typename T1, typename T2, int T4, int T5>
class class2
{};

template<typename T>
using alias1 = int;

/// @brief comment
/// @tparam T comment
template<typename T>
using alias2 = int;

/// @brief comment
template<typename T>
using alias3 = int;
