#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  const std::unordered_map<char, int> kPoint = {
    {')', 3},
    {']', 57},
    {'}', 1197},
    {'>', 25137},
  };

  const std::unordered_map<char, char> kPair = {
    {')', '('},
    {']', '['},
    {'}', '{'},
    {'>', '<'},
  };

  std::string line;
  int score = 0;
  while (std::cin >> line) {
    std::vector<char> stack;
    for (auto c: line) {
      auto it = kPoint.find(c);
      if (it == kPoint.end()) {
        stack.push_back(c);
      } else {
        if (kPair.at(c)  == stack.back()) {
          stack.pop_back();
        } else {
          score += kPoint.at(c);
          break;
        }
      }
    }
  }
  std::cout << score << '\n';
}
