#include <iostream>

class A {
 public:
  A() = default;

  A(A&&) = default;
  A& operator=(A&&) = default;
};

int main() {
  A a;
  A b(a);
}
