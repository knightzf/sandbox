#include <iostream>
#include <memory>
#include <vector>

struct A {
  A() {
    a = std::make_unique<int>(10);
  }
  std::unique_ptr<int> a;
};

int main() {
  std::vector<std::shared_ptr<A>> v;
  auto b = std::make_shared<A>();
  v.push_back(b);
}
