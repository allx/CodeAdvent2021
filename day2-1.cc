#include <iostream>

int main() {
  int x = 0, depth = 0;
  std::string cmd;
  int param;
  while (std::cin >> cmd >> param) {
    if (cmd == "forward") {
      x += param;
    } else if (cmd == "down") {
      depth += param;
    } else if (cmd == "up") {
      depth -= param;
    }
    std::cout << cmd << "(" << param << "): "<< x << ' ' << depth << '\n';
  }
  std::cout << depth * x << '\n';
}

