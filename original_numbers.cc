#include <iostream>
#include <string>
#include <vector>


class Solution {

  static inline const std::vector<std::string> NUMBERS = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  };

  bool dfs(std::vector<int>& map, int totalCount, std::vector<int>& result) {
    if (totalCount == 0) {
      return true;
    }

    for (size_t i = 0; i < NUMBERS.size(); ++i) {
      const std::string& number = NUMBERS[i];
      bool containNumber = takeNumber(map, number);
      result.push_back(i);
      if (!containNumber || !dfs(map, totalCount - number.size(), result)) {
        addNumber(map, number);
        result.pop_back();
        continue;
      }
      return true;
    }
    return false;
  }

  bool takeNumber(std::vector<int>& map, const std::string& number) {
    bool success = true;
    for(char c : number) {
      if (--map[c - 'a'] < 0) {
        success = false;
      }    
    }
    return success;
  }

  void addNumber(std::vector<int>& map, const std::string& number) {
    for(char c : number) {
      ++map[c - 'a'];
    }
  }

  public:
    std::vector<int> findOriginalNumbers(const std::string& input) {
    std::vector<int> map(26, 0);
    for(char c: input) {
      ++map[c - 'a'];
    }
    int totalCount = input.size();
    std::vector<int> result;
    dfs(map, totalCount, result);
    return result;
  }
};

int main() {
  Solution sol;
  std::string input = "niesevehrtfeev";
  for (int i : sol.findOriginalNumbers(input)) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}