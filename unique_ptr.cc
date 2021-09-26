#include <iostream>
#include <memory>

struct A {
  ~A() {
    std::cout<<"dtor"<<std::endl;
  }
};

struct P
{
  std::unique_ptr<A> p;
};

void func() {
  auto p = std::make_unique<A>();
  P obj;
  obj.p = std::move(p);
}

int main() {
  func();
}
