#include<iostream>
using namespace std;

class A {
  int i;
public:
  A(int ii) : i(ii) {//Add a statement here}
      cout << "A's ctor is called" << endl;
}
  ~A() {//Add a statement here}
      cout << "A's dtor is called" << endl;
      }
  void f() const {}
};

class B {
  int i;
public:
  B(int ii) : i(ii) {//Add a statement here
  cout << "b's ctor is called" << endl;}
  ~B() {//Add a statement here
  cout << "b's dtor is called" << endl;}
  void f() const {}
};

class C : public B {
  A a;
public:
  C(int ii) : B(ii), a(ii) {//Add a statement here
  cout << "c's ctor is called" << endl;}
  ~C() {//Add a statement here
  cout << "c's dtor is called" << endl;}
  void f() const {
    a.f();
    B::f();
  }
};

int main() {
  C c(47);

  //calls the b constructor then a construtor then c constructor
  //then c's destructor, a destructor, b's destructor

  return 0;
}
