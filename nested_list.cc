#include <iostream>
#include <vector>

using namespace std;

class NestedList {
public:
  bool isInteger() const;
  int getInteger() const;

  bool isString() const;
  std::string getString() const;

  const vector<NestedList> &getList() const;
};

bool print = true;
void iterate(const vector<NestedList> &list) {
  for (const auto &l : list) {
    if (l.isInteger()) {
      if (print) {
        std::cout << l.getInteger() << std::endl;
      }
      print = !print;
    } else if (l.isString()) {
      if (print) {
        std::cout << l.getString() << std::endl;
      }
      print = !print;
    } else {
      iterate(l.getList());
    }
  }
}

int main() {}