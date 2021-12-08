#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using std::string;

string Sub(const string& v1, const string& v2) {
  string ret;
  for (auto c: v1) {
    if (v2.find(c) == string::npos) {
      ret += c;
    }
  }
  return ret;
}

string Comm(const string& v1, const string& v2) {
  string ret;
  for (auto c: v1) {
    if (v2.find(c) != string::npos) {
      ret += c;
    }
  }
  return ret;
}

bool In(const string& v1, const string& v2) {
  bool in = true;
  for (auto c: v2) {
    if (v1.find(c) == string::npos) {
      in = false;
      break;
    }
  }
  return in;
}

int main() {
  int sum = 0;
  string line;
  while (std::getline(std::cin, line)) {
    std::unordered_map<string, int> v_map;
    std::unordered_map<int, string> s_map;
    std::vector<string> len5;
    std::vector<string> len6;

    std::istringstream ss(line);
    string word;

    for (int i = 0; i < 10; i++) {
      ss >> word;
      std::sort(word.begin(), word.end());
      switch (word.size()) {
        case 2:
          v_map[word] = 1;
          s_map[1] = word;
          break;
        case 3:
          v_map[word] = 7;
          s_map[7] = word;
          break;
        case 4:
          v_map[word] = 4;
          s_map[4] = word;
          break;
        case 5:
          len5.push_back(word);
          break;
        case 6:
          len6.push_back(word);
          break;
        case 7:
          v_map[word] = 8;
          s_map[8] = word;
          break;
      }
    }

    string bd = Sub(s_map[4], s_map[1]);

    for (const auto& x: len5) {
      if (In(x, bd)) {
        v_map[x] = 5;
        s_map[5] = x;
        break;
      }
    }

    for (const auto& x: len5) {
      if (x == s_map[5]) {
        continue;
      } else if (Comm(s_map[5], x).size() == 3) {
        v_map[x] = 2;
        s_map[2] = x;
      } else {
        v_map[x] = 3;
        s_map[3] = x;
      }
    }

    for (const auto& x: len6) {
      if (Comm(bd, x).size() == 1) {
        v_map[x] = 0;
        s_map[0] = x;
      } else if (Comm(s_map[7], x).size() == 3) {
        v_map[x] = 9;
        s_map[9] = x;
      } else {
        v_map[x] = 6;
        s_map[6] = x;
      }
    }

    ss >> word; // '|' ignoring

    int val = 0;
    for (int i = 0; i < 4; i++) {
      val *= 10;
      ss >> word;
      std::sort(word.begin(), word.end());
      val += v_map[word];
    }
    sum += val;
  }
  std::cout << sum << '\n';
}
