#include <iostream>

struct A {
  uint32_t offset;
  uint32_t len;
  uint8_t flags;
};

int main() {
  std::cout<<sizeof(A)<<std::endl;
  std::cout<<sizeof(uint32_t)<<std::endl;
  std::cout<<sizeof(uint8_t)<<std::endl;
}
