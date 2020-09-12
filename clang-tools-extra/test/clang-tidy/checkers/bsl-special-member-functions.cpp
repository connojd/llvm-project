// RUN: %check_clang_tidy %s bsl-special-member-functions %t

class DefaultConstructor {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a default constructor is declared, a copy/move constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  DefaultConstructor() {}
};

class DefaultConstructorDefaulted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a default constructor is declared, a copy/move constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  DefaultConstructorDefaulted() = default;
};

class DefaultConstructorDeleted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a default constructor is declared, a copy/move constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  DefaultConstructorDeleted() = delete;
};

class CopyConstructor {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a copy constructor is declared, a move constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  CopyConstructor(CopyConstructor const &o) {}
};

class CopyConstructorDefaulted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a copy constructor is declared, a move constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  CopyConstructorDefaulted(CopyConstructorDefaulted const &o) = default;
};

class CopyConstructorDeleted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a copy constructor is declared, a move constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  CopyConstructorDeleted(CopyConstructorDeleted const &o) = delete;
};

class MoveConstructor {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a move constructor is declared, a copy constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  MoveConstructor(MoveConstructor &&o) {}
};

class MoveConstructorDefaulted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a move constructor is declared, a copy constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  MoveConstructorDefaulted(MoveConstructorDefaulted &&o) = default;
};

class MoveConstructorDeleted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a move constructor is declared, a copy constructor, a copy/move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  MoveConstructorDeleted(MoveConstructorDeleted &&o) = delete;
};

class CopyAssignment {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a copy assignment operator is declared, a copy/move constructor, a move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  CopyAssignment &operator=(CopyAssignment const &o) {}
};

class CopyAssignmentDefaulted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a copy assignment operator is declared, a copy/move constructor, a move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  CopyAssignmentDefaulted &operator=(CopyAssignmentDefaulted const &o) = default;
};

class CopyAssignmentDeleted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a copy assignment operator is declared, a copy/move constructor, a move assignment operator and a destructor must also be provided [bsl-special-member-functions]
  CopyAssignmentDeleted &operator=(CopyAssignmentDeleted const &o) = delete;
};

class MoveAssignment {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a move assignment operator is declared, a copy/move constructor, a copy assignment operator and a destructor must also be provided [bsl-special-member-functions]
  MoveAssignment &operator=(MoveAssignment &&o) {}
};

class MoveAssignmentDefaulted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a move assignment operator is declared, a copy/move constructor, a copy assignment operator and a destructor must also be provided [bsl-special-member-functions]
  MoveAssignmentDefaulted &operator=(MoveAssignmentDefaulted &&o) = default;
};

class MoveAssignmentDeleted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a move assignment operator is declared, a copy/move constructor, a copy assignment operator and a destructor must also be provided [bsl-special-member-functions]
  MoveAssignmentDeleted &operator=(MoveAssignmentDeleted &&o) = delete;
};

class Destructor {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a destructor is declared, a copy/move constructor and a copy/move assignment operator must also be provided [bsl-special-member-functions]
  ~Destructor() {}
};

class DestructorDefaulted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a destructor is declared, a copy/move constructor and a copy/move assignment operator must also be provided [bsl-special-member-functions]
  ~DestructorDefaulted() = default;
};

class DestructorDeleted {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a destructor is declared, a copy/move constructor and a copy/move assignment operator must also be provided [bsl-special-member-functions]
  ~DestructorDeleted() = delete;
};

class DestructorVirtual {
// CHECK-MESSAGES: [[@LINE-1]]:7: warning: if a destructor is declared, a copy/move constructor and a copy/move assignment operator must also be provided [bsl-special-member-functions]
  virtual ~DestructorVirtual() {}
};

class Success {
  ~Success() {}
  Success(Success const &o) {}
  Success(Success &&o) {}
  Success &operator=(Success const &o) {}
  Success &operator=(Success &&o) {}
};

class SuccessDefaulted {
  ~SuccessDefaulted() = default;
  SuccessDefaulted(SuccessDefaulted const &o) = default;
  SuccessDefaulted(SuccessDefaulted &&o) = default;
  SuccessDefaulted &operator=(SuccessDefaulted const &o) = default;
  SuccessDefaulted &operator=(SuccessDefaulted &&o) = default;
};

class SuccessDeleted {
  ~SuccessDeleted() = delete;
  SuccessDeleted(SuccessDeleted const &o) = delete;
  SuccessDeleted(SuccessDeleted &&o) = delete;
  SuccessDeleted &operator=(SuccessDeleted const &o) = delete;
  SuccessDeleted &operator=(SuccessDeleted &&o) = delete;
};

class SuccessWithDefaultCtor {
  SuccessWithDefaultCtor() {}
  ~SuccessWithDefaultCtor() {}
  SuccessWithDefaultCtor(SuccessWithDefaultCtor const &o) {}
  SuccessWithDefaultCtor(SuccessWithDefaultCtor &&o) {}
  SuccessWithDefaultCtor &operator=(SuccessWithDefaultCtor const &o) {}
  SuccessWithDefaultCtor &operator=(SuccessWithDefaultCtor &&o) {}
};

class SuccessWithDefaultCtorDefaulted {
  SuccessWithDefaultCtorDefaulted() = default;
  ~SuccessWithDefaultCtorDefaulted() = default;
  SuccessWithDefaultCtorDefaulted(SuccessWithDefaultCtorDefaulted const &o) = default;
  SuccessWithDefaultCtorDefaulted(SuccessWithDefaultCtorDefaulted &&o) = default;
  SuccessWithDefaultCtorDefaulted &operator=(SuccessWithDefaultCtorDefaulted const &o) = default;
  SuccessWithDefaultCtorDefaulted &operator=(SuccessWithDefaultCtorDefaulted &&o) = default;
};

class SuccessWithDefaultCtorDeleted {
  SuccessWithDefaultCtorDeleted() = delete;
  ~SuccessWithDefaultCtorDeleted() = delete;
  SuccessWithDefaultCtorDeleted(SuccessWithDefaultCtorDeleted const &o) = delete;
  SuccessWithDefaultCtorDeleted(SuccessWithDefaultCtorDeleted &&o) = delete;
  SuccessWithDefaultCtorDeleted &operator=(SuccessWithDefaultCtorDeleted const &o) = delete;
  SuccessWithDefaultCtorDeleted &operator=(SuccessWithDefaultCtorDeleted &&o) = delete;
};

class SuccessWithVirtualDestructor {
  SuccessWithVirtualDestructor() {}
  virtual ~SuccessWithVirtualDestructor() {}
  SuccessWithVirtualDestructor(SuccessWithVirtualDestructor const &o) {}
  SuccessWithVirtualDestructor(SuccessWithVirtualDestructor &&o) {}
  SuccessWithVirtualDestructor &operator=(SuccessWithVirtualDestructor const &o) {}
  SuccessWithVirtualDestructor &operator=(SuccessWithVirtualDestructor &&o) {}
};
