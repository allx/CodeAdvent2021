#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

long long Total(long long cache[9][257], int timer, int day) {
  if (day < 0) {
    return 0;
  } else if (timer >= day) {
    return 1;
  } else if (cache[timer][day] >= 0) {
    return cache[timer][day];
  } else {
    long long val = Total(cache, 6, day-timer-1) + Total(cache, 8, day-timer-1);
    cache[timer][day] = val;
    return cache[timer][day];
  }
}

int main() {
  long long cache[9][257];
  memset(cache, -1, sizeof(cache));
  long long sum = 0;
  int v;
  while(std::cin >> v) {
    sum += Total(cache, v, 256);
    char c;
    if(!(std::cin >> c)) {
      break;
    }
  }


  std::cout << sum << '\n';
}
