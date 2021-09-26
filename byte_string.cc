#include <string>
#include <iostream>
#include <boost/endian/conversion.hpp>

using boost::endian::native_to_big;

template <typename T>
std::string toByteString(T t) {
    T val = native_to_big(t);
    return std::string(reinterpret_cast<char*>(&val), sizeof(val));
}

int main() {
  uint32_t a = 1;
  for(char c : toByteString(a)) {
    std::cout<<(int)c<<" ";
  }
  std::cout<<std::endl;
}
