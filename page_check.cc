#include <iostream>

int main() {
  int a = 0;
  if(!((a++) & 0xff)) {
    std::cout<< "break "<<std::endl;
  }
}
