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
class DependentBase0
{
public:
  using value_type = long;
  typedef int TYPE;
  void g();
  unsigned int var;

private:
  long c;
};

template <typename T>
class DependentBase1 {
public:
  unsigned int b;
};

template <typename T>
class A : public DependentBase0<T>
{
public:
  using A_uint32 = value_type;
  // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  typedef TYPE A_int32;
  // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

  value_type data0;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  const TYPE data1;
  // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

  TYPE volatile data2;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

  template<int X> class sub0;

  template<value_type X> class sub1;
  // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  template<const value_type X> class sub2;
  // CHECK-MESSAGES: :[[@LINE-1]]:18: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  template<n1::TYPE X> class sub3;

private:
  TYPE *data3;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

public:
  TYPE f1()
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here
  {
    volatile int b;
    const TYPE t = 0 + b + c;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
    // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

    g();
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: multiple declarations with name 'g' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :13:6: note: using the declaration of 'g' found here
    // CHECK-MESSAGES: :21:8: note: but also found declaration of 'g' in base class here

    n1::value_type myvar = 0;

    auto la = [](int var) { return var; };

    var = 0;
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: multiple declarations with name 'var' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :12:11: note: using the declaration of 'var' found here
    // CHECK-MESSAGES: :22:16: note: but also found declaration of 'var' in base class here

    return var;
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: multiple declarations with name 'var' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :12:11: note: using the declaration of 'var' found here
    // CHECK-MESSAGES: :22:16: note: but also found declaration of 'var' in base class here
  }

  [[maybe_unused]] void* f2()
  {
    n1::TYPE t1 = 0;
    n1::g();
    typename DependentBase0<T>::TYPE t2 = 0;

    return nullptr;
  }

  const value_type f3()
  // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here
  {
        return 0;
  }

  long f4(value_type const volatile arg0)
  // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here
  {
        return arg0 * arg0;
  }
};

template <typename T> class DependentBase2 : public DependentBase0<T> {};

template <typename T> class A1 : public DependentBase2<T>, public DependentBase1<T>
{
public:
  using A_uint32 = value_type;
  // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  typedef TYPE A_int32;
  // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

  value_type data0;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  const TYPE data1;
  // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

  TYPE volatile data2;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

  template<int X> class sub0;

  template<value_type X> class sub1;
  // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  template<const value_type X> class sub2;
  // CHECK-MESSAGES: :[[@LINE-1]]:18: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here

  template<n1::TYPE X> class sub3;

private:
  TYPE *data3;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

public:
  TYPE f1()
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
  // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here
  {
    volatile int b;
    const TYPE t = 0 + b + c;
    // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: multiple declarations with name 'TYPE' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :9:7: note: using the declaration of 'TYPE' found here
    // CHECK-MESSAGES: :20:15: note: but also found declaration of 'TYPE' in base class here

    g();
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: multiple declarations with name 'g' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :13:6: note: using the declaration of 'g' found here
    // CHECK-MESSAGES: :21:8: note: but also found declaration of 'g' in base class here

    n1::value_type myvar = 0;

    auto la = [](int var) { return var; };

    var = 0;
    // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: multiple declarations with name 'var' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :12:11: note: using the declaration of 'var' found here
    // CHECK-MESSAGES: :22:16: note: but also found declaration of 'var' in base class here

    return var;
    // CHECK-MESSAGES: :[[@LINE-1]]:12: warning: multiple declarations with name 'var' found; need to qualify the name here [bsl-dependent-base-name]
    // CHECK-MESSAGES: :12:11: note: using the declaration of 'var' found here
    // CHECK-MESSAGES: :22:16: note: but also found declaration of 'var' in base class here
  }

  [[maybe_unused]] void* f2()
  {
    n1::TYPE t1 = 0;
    n1::g();
    typename DependentBase0<T>::TYPE t2 = 0;

    return nullptr;
  }

  const value_type f3()
  // CHECK-MESSAGES: :[[@LINE-1]]:9: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here
  {
        return 0;
  }

  long f4(value_type const volatile arg0)
  // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: multiple declarations with name 'value_type' found; need to qualify the name here [bsl-dependent-base-name]
  // CHECK-MESSAGES: :10:7: note: using the declaration of 'value_type' found here
  // CHECK-MESSAGES: :19:9: note: but also found declaration of 'value_type' in base class here
  {
        return arg0 * arg0 + b;
        // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: multiple declarations with name 'b' found; need to qualify the name here [bsl-dependent-base-name]
        // CHECK-MESSAGES: :12:5: note: using the declaration of 'b' found here
        // CHECK-MESSAGES: :31:16: note: but also found declaration of 'b' in base class here
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
    typename DependentBase0<T>::TYPE t2 = 0;
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

  value_type f3()
  {
    return 0;
  }
};
}
