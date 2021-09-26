#include <iostream>

int main() {
  if(false && (int i = 0; i < 10)) {
    std::cout<<i<<std::endl;
  }
}
