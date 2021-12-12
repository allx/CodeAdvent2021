#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void Explore(std::unordered_map<std::string, std::vector<std::string>>& edges,
             const std::string& node,
             std::unordered_set<std::string>& visited,
             int& path) {

  if (node == "end") {
    path++;
    return;
  }

  if (node[0] >= 'a') {
    if (visited.find(node) != visited.end()) {
      return;
    }
    visited.insert(node);
  }

  for (const auto& next: edges[node]) {
    Explore(edges, next, visited, path);
  }

  visited.erase(node);
}

int main() {
  std::unordered_map<std::string, std::vector<std::string>> edges;
  std::string line;

  while (std::cin >> line) {
    auto pos = line.find("-");
    std::string a = line.substr(0, pos);
    std::string b = line.substr(pos+1);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int path = 0;
  std::unordered_set<std::string> visited;

  Explore(edges, "start", visited, path);

  std::cout << path << '\n';
}

