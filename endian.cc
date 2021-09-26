#include <iostream>

using namespace std;

int main() {
  uint32_t a = 1;
  std::cout<< (int)*((char*)&a) <<std::endl;
}
