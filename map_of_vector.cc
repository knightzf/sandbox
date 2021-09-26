#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  //std::map<std::string, std::vector<std::string>> m;
  //m.emplace("aaa", std::vector<std::string>{"bbb"});
  std::map<std::string, std::vector<std::string>> m{{"aaa", {"bbb"}}};
}
