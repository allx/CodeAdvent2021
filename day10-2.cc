#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  const std::unordered_map<char, int> kPoint = {
    {'(', 1},
    {'[', 2},
    {'{', 3},
    {'<', 4},
  };

  const std::unordered_map<char, char> kPair = {
    {')', '('},
    {']', '['},
    {'}', '{'},
    {'>', '<'},
  };

  std::string line;
  std::vector<long long> scores;

  while (std::cin >> line) {

    std::vector<char> stack;
    bool corrupted = false;

    for (auto c: line) {
      auto it = kPair.find(c);
      if (it == kPair.end()) {
        stack.push_back(c);
      } else {
        if (kPair.at(c)  == stack.back()) {
          stack.pop_back();
        } else {
          corrupted = true;
          break;
        }
      }
    }

    if (corrupted || stack.empty()) {
      continue;
    }

    long long score = 0;
    while (!stack.empty()) {
      score *= 5;
      score += kPoint.at(stack.back());
      stack.pop_back();
    }

    scores.push_back(score);
  }

  std::sort(scores.begin(), scores.end());
  std::cout << scores[scores.size()/2] << '\n';
}

