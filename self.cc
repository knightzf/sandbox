#include <iostream>

int main() {
  int x = 1;
  auto a = [self(x)] () {
    std::cout<<self<<std::endl;
  };
  a();
}
