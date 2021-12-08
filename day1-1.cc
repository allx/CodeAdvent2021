#include <iostream>

int main() {
  int prev = 9999;
  int cnt = 0;
  int now;
  while (std::cin >> now) {
    if (now > prev) {
      cnt++;
    }
    prev = now;
  }
  std::cout << cnt << '\n';
}
