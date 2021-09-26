#include <string>
#include <iostream>

int main() {
  std::string a(5, 255);
  for(char c : a) {
    std::cout << (int)(uint8_t(c)) << std::endl;
  }
}
