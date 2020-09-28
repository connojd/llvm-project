.. title:: clang-tidy - bsl-dependent-base-name

bsl-dependent-base-name
=======================

Warns whenever an unqualified, non-dependent name is used in a class
template such that 1) the name is declared in a dependent base class
of the class template and 2) the name is declared in an enclosing scope
of the class template.

The C++ lookup rules dictate that in this situation, the non-dependent name
is bound to the declaration found in the enclosing scope rather than the
dependent base class, which may subvert developer expectations.

Example:

.. code-block:: c++

  using value_type = long;
  int b, c, var;
  void g();

  template <typename T>
  class Base {
  public:
    using value_type = int;
    void g(){}

  protected:
    long b;

  private:
    int c;
  };

  template <typename T>
  class Derived : Base<T>
  {
  public:
    using my_type = value_type; // Warning here, found 'value_type' in dependent base class 'Base' and at global scope

    void f0()
    {
        g(); // Warning here, found 'g' in dependent base class 'Base' and at global scope
    }

    long f1()
    {
        return b + 1; // Warning here, found 'b' in dependent base class 'Base' and at global scope
    }

    long f2()
    {
        return this->b + 2; // No warning
    }

    long f3()
    {
        return ::b + 3; // No warning
    }

    int f4()
    {
        return c; // No warning, 'c' is private in dependent base class 'Base', uses 'c' found at global scope.
    }

  private:
    value_type data0; // Warning here, found 'value_type' in dependent base class 'Base' and at global scope
    my_type data1; // No warning here, (already accounted for in warning of 'my_type' using declaration)

    template <value_type X> class priv_class; // Warning here, found 'value_type' in dependent base class 'Base' and at global scope

    ::value_type data2; // No warning, name is qualified
    Base<T>::value_type data3; // No warning, name is qualified
  };
