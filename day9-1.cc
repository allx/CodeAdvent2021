#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> h_map;
  std::string line;
  while (std::cin >> line) {
    h_map.emplace_back(line);
  }


  int risk = 0;
  for (int i = 0; i < h_map.size(); i++) {
    for (int j = 0; j < h_map[0].size(); j++) {
      if ((i-1<0 || h_map[i-1][j]>h_map[i][j]) &&
          (i+1>=h_map.size() || h_map[i+1][j]>h_map[i][j]) &&
          (j-1<0 || h_map[i][j-1]>h_map[i][j]) &&
          (j+1>=h_map[0].size() || h_map[i][j+1]>h_map[i][j])) {
        risk += h_map[i][j]-'0'+1;
      }
    }
  }
  std::cout << risk << '\n';
  return 0;
}
