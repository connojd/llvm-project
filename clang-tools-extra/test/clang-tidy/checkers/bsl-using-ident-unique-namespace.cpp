// RUN: %check_clang_tidy %s bsl-using-ident-unique-namespace %t

using type1 = int;
using _reserved1 = int;
void foo1(int);
template<typename T, int I>
void templateFoo1(int);
template<typename T, int I>
using templateType1 = int;
class c1{};
struct s1{};
enum e1{};
union u1{};

// detect function names?

namespace n1
{
	using _reserved1 = int; // Compliant by exception

	void foo2(int type1); // Compliant

	template<typename T, int I>
	void templateFoo2(int type1); // Compliant

	void foo3()
	{
		int type1; // Compliant
	}
}

namespace n1
{
	template<typename T, int I>
	using templateType1 = int;
	// CHECK-MESSAGES: [[@LINE-1]]:8: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

	template<typename T, int I>
	using templateType2 = int; // Compliant
}

namespace n1
{
	class c1{};
	// CHECK-MESSAGES: [[@LINE-1]]:8: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]
	struct s1{};
	// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]
	enum e1{};
	// CHECK-MESSAGES: [[@LINE-1]]:7: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]
	union u1{};
	// CHECK-MESSAGES: [[@LINE-1]]:8: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]
}

namespace n1
{
	using type1 = int;
	// CHECK-MESSAGES: [[@LINE-1]]:8: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

	using type2 = int; // Compliant

	namespace n1n1
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	namespace n1n2
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	class n1c1
	{
	public:
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	class n1c2
	{
	public:
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	struct n1s1
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	struct n1s2
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};
};

namespace n2
{
	using type1 = int;
	// CHECK-MESSAGES: [[@LINE-1]]:8: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

	using type2 = int; // Compliant

	namespace n2n1
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	namespace n2n2
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	class n2c1
	{
	public:
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	class n2c2
	{
	public:
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	struct n2s1
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};

	struct n2s2
	{
		using type1 = int;
		// CHECK-MESSAGES: [[@LINE-1]]:9: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]

		using type3 = int; // Compliant
	};
};

class myclass_base
{
public:
	myclass_base() = default;
	~myclass_base() = default;
	myclass_base(myclass_base const &) = default;
	myclass_base &operator=(myclass_base const &) = default;
	myclass_base(myclass_base &&) = default;
	myclass_base &operator=(myclass_base &&) = default;
};

class prototypeTest1;
class prototypeTest1{};

template<typename T>
class templateClass
{
	using templateClassType = T;
};

templateClass<int> templateClassTest1;
templateClass<bool> templateClassTest2;

template<typename T>
bool templateFunc1()
{
	using templateFuncType = T;
	return true;
}

auto templateFuncTest1{templateFunc1<int>()};
auto templateFuncTest2{templateFunc1<bool>()};

template<typename T>
bool templateFunc2(int)
{
	return true;
}

template<typename T>
bool templateFunc2(bool)
{
	return true;
}

namespace n1
{
	template<typename T>
	bool templateFunc1()
	// CHECK-MESSAGES: [[@LINE-1]]:7: warning: A user-defined type name shall be a unique identifier within a namespace [bsl-using-ident-unique-namespace]
	{
		return true;
	}
}

template<template<class...> class C>
class templateTemplateClass
{};

using templateTemplateClassTest = templateTemplateClass<templateClass>;

template<bool B, typename T = void>
struct enable_if final
{};

template<typename T>
struct enable_if<true, T> final
{
	using type = T;
};

template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

template<typename T, T v>
class integral_constant
{
public:
	static constexpr T value{v};
};

template<bool B>
using bool_constant = integral_constant<bool, B>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template<typename T, typename U>
class is_same final : public false_type
{};

template<typename T>
class is_same<T, T> final : public true_type
{};

template<          // --
	typename T,    // --
	enable_if_t<is_same<T, bool>::value, bool> = true>
[[nodiscard]] constexpr auto
foo() noexcept -> bool
{
	return true;
}

template<          // --
	typename T,    // --
	enable_if_t<!is_same<T, bool>::value, bool> = true>
[[nodiscard]] constexpr auto
foo() noexcept -> bool
{
	return false;
}

auto bar{foo<bool>()};

class classWithConstructors
{
public:
	classWithConstructors()
	{}

	classWithConstructors(int val)
	{}

	template<typename T>
	classWithConstructors(T val) = delete;
};

classWithConstructors classWithConstructorsTest;
