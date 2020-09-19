// RUN: %check_clang_tidy %s bsl-dependent-base-name %t

namespace n1 {
namespace n0 {
    using value_type = int;
}

using TYPE = long;
using value_type = n0::value_type;
int b, c, var;
void g();

template <typename T>
class B;

// TODO add test for inheritance chain > 2
// TODO add test for out-of-line usage of names and references
template <typename T>
class B
{
public:
  typedef int TYPE;
  using value_type = long;
  void g();

protected:
  int b;

private:
  int c;
};

template <typename T>
class A : public B<T>
{
public:
  //using value_type = unsigned int;
  using A_uint32 = value_type;
  typedef TYPE A_int32;

  value_type data0;
  const TYPE data1;
  TYPE volatile data2;

  template<int X> class sub0;
  template<value_type X> class sub1;
  template<const value_type X> class sub2;
  template<n1::TYPE X> class sub3;

private:
  TYPE *data3;

public:
  TYPE f1()
  {
    volatile int b;
    const TYPE t = 0 + b + c;
    g();
    n1::value_type myvar = 0;

    auto la = [](int b) { return b; };

    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: in a class template with a dependent base, any name that may be found in that dependent base shall be referred to using a qualified-id or this->. [bsl-dependent-base-name]
    var = 0;
    return var;
  }

  [[maybe_unused]] void* f2()
  {
    n1::TYPE t1 = 0;  // Compliant - explicit use global TYPE
    n1::g();    // Compliant - explicit use global func
    typename B<T>::TYPE t2 = 0; // Compliant - explicit use base TYPE

    return nullptr;
  }

  const value_type f3()
  {
        return 0;
  }

  long f4(value_type const volatile arg0)
  {
        return arg0 * arg0;
  }
};

// All compliant

template class A<int>;
class C {};

template <typename T>
class D : public C
{
  void f1()
  {
    TYPE t = 0;
    g();
  }

  void f2()
  {
    n1::TYPE t1 = 0;
    n1::g();
    typename B<T>::TYPE t2 = 0;
    this->g();
  }
};

class E : C
{
  void f1()
  {
    TYPE t = 0;
    g();
  }

  void f2 ( )
  {
    n1::TYPE t1 = 0;
    n1::g();
  }
};
}
