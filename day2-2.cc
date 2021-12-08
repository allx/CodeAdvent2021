#include <iostream>

int main() {
  int x = 0, depth = 0, aim = 0;
  std::string cmd;
  int param;
  while (std::cin >> cmd >> param) {
    if (cmd == "forward") {
      x += param;
      depth += param*aim;
    } else if (cmd == "down") {
      aim += param;
    } else if (cmd == "up") {
      aim -= param;
    }
    std::cout << cmd << "(" << param << "): "<< x << ' ' << depth << '\n';
  }
  std::cout << depth * x << '\n';
}

