// RUN: %check_clang_tidy %s bsl-implicit-conversions-forbidden %t

class classWithBoolOperator
{
public:
    [[nodiscard]] constexpr operator bool() const noexcept
    {
        return true;
    }
};

bool functionThatTakesACString(const char *str)
{
    return true;
}

bool test{functionThatTakesACString("Hello World")};

void foo()
{
    unsigned var1 = 42;
    // CHECK-MESSAGES: :[[@LINE-1]]:21: warning: implicit conversions are forbidden (IntegralCast from int to unsigned int) [bsl-implicit-conversions-forbidden]

    int var2 = 42;
    bool test;

    if (test) {
    }

    classWithBoolOperator c{};
    if (c) {
    }

    short s1{static_cast<short>(42)};
    short s2{static_cast<short>(42)};

    if (s1 == s2) {
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: implicit conversions are forbidden (IntegralCast from short to int) [bsl-implicit-conversions-forbidden]
    // CHECK-MESSAGES: :[[@LINE-2]]:15: warning: implicit conversions are forbidden (IntegralCast from short to int) [bsl-implicit-conversions-forbidden]
    }

    int i = s1;
    // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: implicit conversions are forbidden (IntegralCast from short to int) [bsl-implicit-conversions-forbidden]
}

bool
funcThatReturnsBool1()
{
    return true;
}

bool
funcThatReturnsBool2()
{
    return true;
}

void
testFunctionsThatReturnBool()
{
    if (funcThatReturnsBool1() == funcThatReturnsBool2()) {
    }
}

char
funcThatReturnsChar1()
{
    return 'A';
}

void
testFunctionsThatReturnChar()
{
    if (funcThatReturnsChar1() == 'A') {
    }
}

unsigned char
funcThatReturnsUnsignedChar1()
{
    return static_cast<unsigned char>(42);
}

unsigned char
funcThatReturnsUnsignedChar2()
{
    return static_cast<unsigned char>(42);
}

void
testFunctionsThatReturnUnsignedChar()
{
    if (funcThatReturnsUnsignedChar1() == funcThatReturnsUnsignedChar2()) {
    // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: implicit conversions are forbidden (IntegralCast from unsigned char to int) [bsl-implicit-conversions-forbidden]
    // CHECK-MESSAGES: :[[@LINE-2]]:43: warning: implicit conversions are forbidden (IntegralCast from unsigned char to int) [bsl-implicit-conversions-forbidden]
    }
}
