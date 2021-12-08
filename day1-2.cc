#include <iostream>
#include <deque>

int main() {
  int cnt = 0;
  int now;
  int sum = 0;
  std::deque<int> nums;

  for (int i = 0; i < 3; i++) {
    std::cin >> now;
    nums.push_back(now);
    sum += now;
  }

  int prev = sum;

  while (std::cin >> now) {
    sum -= nums.front();
    sum += now;
    nums.pop_front();
    nums.push_back(now);

    if (sum > prev) {
      cnt++;
    }
    prev = sum;
  }
  std::cout << cnt << '\n';
}
