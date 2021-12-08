#include <iostream>
#include <functional>
#include <vector>

std::vector<int> FilterBits(const std::vector<std::string>& report,
                            const std::vector<int> &idx,
                            int pos,
                            std::function<char(int, int)> cmp) {

  int cnt = 0;
  for (int i: idx) {
    if (report[i][pos] == '1') {
      cnt++;
    }
  }


  std::vector<int> candidate;
  //char to_match = (cnt >= idx.size()/2 ? '1': '0');
  char to_match = cmp(cnt, idx.size());
  //std::cout << "idx:" << idx.size() << " pos:" << pos << " 1s:" << cnt << " to_match:" << to_match << std::endl;
  for (int i: idx) {
    if (report[i][pos] == to_match) {
      //std::cout << report[i] << ' ';
      candidate.push_back(i);
    }
  }
  //std::cout << std::endl;
  return candidate;
}

int BitsToInt(const std::string& bits) {
  int val = 0;
  for (auto c: bits) {
    val <<= 1;
    if (c == '1') {
      val++;
    }
  }
  //std::cout << bits << " --> " << val << '\n';
  return val;
}

int main() {
  std::vector<std::string> report;
  std::string line;
  while (std::cin >> line) {
    report.emplace_back(line);
  }

  std::vector<int> idx;
  for (int i = 0; i < report.size(); i++) {
    idx.push_back(i);
  }

  int oxygen = 0, co2 = 0;

  int pos = 0;
  std::vector<int> prev_idx = idx;
  while (true) {
    auto new_idx = FilterBits(report, prev_idx, pos++,
                              [](int lhp, int rhp) -> char {
                                return lhp >= rhp-lhp ? '1' : '0';
                              });
    //std::cout << "idx: " << prev_idx.size() << ' ' << new_idx.size() << '\n';
    if (new_idx.size() == 1) {
      oxygen = BitsToInt(report[new_idx.front()]);
      break;
    }
    prev_idx = std::move(new_idx);
  }

  pos = 0;
  prev_idx = idx;
  while (true) {
    auto new_idx = FilterBits(report, prev_idx, pos++,
                              [](int lhp, int rhp) -> char {
                                return lhp < rhp-lhp ? '1' : '0';
                              });
    if (new_idx.size() == 1) {
      co2 = BitsToInt(report[new_idx.front()]);
      break;
    }
    prev_idx = std::move(new_idx);
  }

  std::cout << oxygen << ' ' << co2 << ' ' << oxygen*co2 << '\n';
}

