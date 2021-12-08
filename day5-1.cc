#include <iostream>
#include <cstring>

int main() {
  const int kMax = 1000;
  int boards[kMax][kMax];
  memset(boards, 0, sizeof(boards));

  int x1, y1, x2, y2;
  char c;
  while (std::cin >> x1 >> c >> y1 >> c >> c >> x2 >> c >> y2) {
    if (x1 == x2 || y1 == y2) {
      for (int x = std::min(x1, x2); x <= std::max(x1, x2); x++) {
        for (int y = std::min(y1, y2); y <= std::max(y1, y2); y++) {
          boards[x][y]++;
        }
      }
    } else if (abs(x1-x2) == abs(y1-y2)) {
      if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
      }
      if (y1 < y2) {
        do {
          boards[x1++][y1++]++;
        } while (x1 <= x2);
      } else {
        do {
          boards[x1++][y1--]++;
        } while (x1 <= x2);
      }
    }
  }
  int cnt = 0;
  for (int x = 0; x < kMax; x++) {
    for (int y = 0; y < kMax; y++) {
      if (boards[x][y] >= 2) {
        cnt++;
      }
    }
  }
  std::cout << cnt << '\n';
}
