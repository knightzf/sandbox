#include <memory>
#include <iostream>

using ABC = std::unique_ptr<int>;

int main() {
  ABC a = std::make_unique<int>(1);
}
