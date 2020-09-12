// RUN: %check_clang_tidy %s bsl-forward-reference-overloaded %t

void fucntionWithForwardReference1(int i)
{}

template<typename T>
void fucntionWithForwardReference1(T &&t)
// CHECK-MESSAGES: :[[@LINE-1]]:40:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
{}

void fucntionWithForwardReference2(int i, int j)
{}

template<typename T>
void fucntionWithForwardReference2(int i, T &&t)
// CHECK-MESSAGES: :[[@LINE-1]]:47:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
{}

void fucntionWithForwardReference3(int i, int j, int k)
{}

template<typename T>
void fucntionWithForwardReference3(int i, T &&t, int k)
// CHECK-MESSAGES: :[[@LINE-1]]:47:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
{}

void fucntionWithForwardReference4(int i, int j, int k)
{}

template<typename T>
void fucntionWithForwardReference4(int i, T &&t, bool b)
{}

void fucntionWithForwardReference5(int i, int j)
{}

template<typename T, typename U>
void fucntionWithForwardReference5(T &&t, U &&u)
// CHECK-MESSAGES: :[[@LINE-1]]:47:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
{}

template<typename T>
void fucntionWithForwardReference6(T &&t)
{}

template<typename T, typename U>
void fucntionWithForwardReference7(T &&t, U &&u)
{}

void fucntionWithForwardReference8(int i)
{}

template<typename T>
void fucntionWithForwardReference9(int i, T &&t)
{}

template<typename T, typename U>
void fucntionWithForwardReference9(int i, T &&t, U &&u)
{}

void fucntionWithForwardReference10(int i)
{}

template<typename T>
void fucntionWithForwardReference10(T &t)
{}

template<typename T>
void fucntionWithForwardReference10(T const &t)
{}

template<typename T>
void fucntionWithForwardReference10(T const &&t)
{}

template<typename T>
void fucntionWithForwardReference10(int &i)
{}

template<typename T>
void fucntionWithForwardReference10(int const &i)
{}

template<typename T>
void fucntionWithForwardReference10(int &&i)
{}

template<typename T>
void fucntionWithForwardReference10(int const &&i)
{}

class classWithForwardReference1
{
public:
  classWithForwardReference1(int i)
  {}

  template<typename T>
  classWithForwardReference1(T &&t)
  // CHECK-MESSAGES: :[[@LINE-1]]:34:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
  {}
};

class classWithForwardReference2
{
public:
  classWithForwardReference2(int i, int j)
  {}

  template<typename T, typename U>
  classWithForwardReference2(T &&t, U &&u)
  // CHECK-MESSAGES: :[[@LINE-1]]:41:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
  {}
};

class classWithForwardReference3
{
public:
  template<typename T>
  classWithForwardReference3(T &&t)
  {}
};

class classWithForwardReference4
{
public:
  template<typename T, typename U>
  classWithForwardReference4(T &&t, U &&u)
  {}
};

class classWithForwardReference5
{
public:
  template<typename T, typename U>
  classWithForwardReference5(int i, T &&t, U &&u)
  {}
};

class classWithForwardReference6
{
public:
  classWithForwardReference6(int i)
  {}

  template<typename T>
  classWithForwardReference6(T &t)
  {}

  template<typename T>
  classWithForwardReference6(T const &t)
  {}

  template<typename T>
  classWithForwardReference6(T const &&t)
  {}

  template<typename T>
  classWithForwardReference6(int &i)
  {}

  template<typename T>
  classWithForwardReference6(int const &i)
  {}

  template<typename T>
  classWithForwardReference6(int &&i)
  {}

  template<typename T>
  classWithForwardReference6(int const &&i)
  {}
};

template<typename T>
class classWithForwardReference7
{
public:
  classWithForwardReference7(int i)
  {}

  classWithForwardReference7(T &&t)
  {}
};

template<typename T>
class classWithForwardReference8
{
public:
  classWithForwardReference8(int i)
  {}

  template<typename U>
  classWithForwardReference8(U &&u)
  // CHECK-MESSAGES: :[[@LINE-1]]:34:  warning: A function that contains an ambiguous forwarding reference as an argument shall not be overloaded. [bsl-forward-reference-overloaded]
  {}
};
