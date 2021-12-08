#include <iostream>
#include <vector>

int main() {
  std::vector<int> fish;
  int v;
  while(std::cin >> v) {
    fish.push_back(v);
    char c;
    if(!(std::cin >> c)) {
      break;
    }
  }
  for (int i = 1; i <= 80; i++) {
    int k = fish.size();
    for (int j = 0; j < k; j++) {
      if (fish[j] == 0) {
        fish[j] = 6;
        fish.push_back(8);
      } else {
        fish[j]--;
      }
    }
    std::cout << "day-" << i << ": " << fish.size() << '\n';
  }
}
