#include <fstream>

int main() {
  std::ofstream f("/tmp/a.txt");
  f << "bbb";
}
