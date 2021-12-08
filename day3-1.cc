#include <vector>
#include <iostream>

int main() {
  std::string bin;
  std::cin >> bin;
  std::vector<int> cnts(bin.size());
  int total = 0;
  while (std::cin) {
    total++;
    for (int i = 0; i < bin.size(); i++) {
      if (bin[i] == '1') {
        cnts[i]++;
      }
    }
    std::cin >> bin;
  }
  int gamma = 0, epsilon = 0;

  for (auto cnt: cnts) {
    gamma <<= 1;
    epsilon <<= 1;
    if (cnt > total/2) {
      gamma++;
    } else {
      epsilon++;
    }
  }

  std::cout << gamma << ' ' << epsilon << ' ' << gamma*epsilon << '\n';
}

