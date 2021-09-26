#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream input("/tmp/a.sfsf", std::ios::binary);
  std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(input), {});
  std::cout<<buffer.size()<<std::endl;
  std::cout<<111<<std::endl;
}
