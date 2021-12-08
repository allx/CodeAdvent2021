#include <iostream>
#include <sstream>
#include <unordered_set>

int main() {
  int cnt = 0;
  std::string line;
  std::unordered_set<int> unique{2, 3, 4, 7};
  while (std::getline(std::cin, line)) {
    std::istringstream ss(line);
    std::string word;

    for (int i = 0; i < 10; i++) {
      ss >> word;
    }

    ss >> word; // '|' ignoring

    for (int i = 0; i < 4; i++) {
      ss >> word;
      if (unique.find(word.size()) != unique.end()) {
        cnt++;
      }
    }
  }
  std::cout << cnt << '\n';
}
