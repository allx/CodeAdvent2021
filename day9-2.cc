#include <iostream>
#include <vector>
#include <queue>

int Explore(const std::vector<std::string>& h_map,
             int x, int y,
             std::vector<std::vector<bool>>& visited) {

  if (x < 0 || x >= h_map.size() || y < 0 || y >= h_map[0].size()) {
    return 0;
  }
  if (visited[x][y]) {
    return 0;
  }

  visited[x][y] = true;

  if (h_map[x][y] == '9') {
    return 0;
  }

  return 1 +
      Explore(h_map, x-1, y, visited) +
      Explore(h_map, x+1, y, visited) +
      Explore(h_map, x, y-1, visited) +
      Explore(h_map, x, y+1, visited);
}

int main() {
  std::vector<std::string> h_map;
  std::string line;
  while (std::cin >> line) {
    h_map.emplace_back(line);
  }

  std::vector<std::vector<bool>> visited(h_map.size(),
                                         std::vector<bool>(h_map[0].size()));

  std::priority_queue<int> pq;
  for (int i = 0; i < h_map.size(); i++) {
    for (int j = 0; j < h_map[0].size(); j++) {
      if ((i-1<0 || h_map[i-1][j]>h_map[i][j]) &&
          (i+1>=h_map.size() || h_map[i+1][j]>h_map[i][j]) &&
          (j-1<0 || h_map[i][j-1]>h_map[i][j]) &&
          (j+1>=h_map[0].size() || h_map[i][j+1]>h_map[i][j])) {
        pq.push(Explore(h_map, i, j, visited));
      }
    }
  }

  int prod = 1;
  for (int i = 0; i < 3; i++) {
    prod *= pq.top();
    pq.pop();
  }
  std::cout << prod << '\n';
  return 0;
}
