#include <iostream>
#include <vector>
#include <climits>

int Dist(const std::vector<int>& vec, int val) {
  int sum = 0;
  for (const auto& v: vec) {
    // sum += abs(v-val); // part1
    int dv = abs(v-val);
    sum += dv*(dv+1)/2;
  }
  return sum;
}

int main() {
  std::vector<int> pos;
  int left = INT_MAX, right = INT_MIN;
  while(true) {
    int x;
    std::cin >> x;
    left = std::min(left, x);
    right = std::max(right, x);
    pos.push_back(x);
    char c;
    if (!(std::cin >> c)) {
      break;
    }
  }

  while(true) {
    int mid = (left + right) / 2;
    int mv = Dist(pos, mid);

    if (left < mid) {
      int lv = Dist(pos, mid-1);
      if (lv < mv) {
        right = mid-1;
        continue;
      }
    }

    if (mid < right) {
      int rv = Dist(pos, mid+1);
      if (rv < mv) {
        left = mid+1;
        continue;
      }
    }

    std::cout << mv << '\n';
    break;
  }
}

