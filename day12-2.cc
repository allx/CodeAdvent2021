#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void Explore(std::unordered_map<std::string, std::vector<std::string>>& edges,
             const std::string& node,
             std::unordered_set<std::string>& visited,
             int& path, bool re_enter = true) {

  if (node == "end") {
    path++;
    return;
  }

  if (node == "start") {
    return;
  }

  if (node[0] >= 'a') {
    if (visited.find(node) != visited.end() && re_enter) {
      for (const auto& next: edges[node]) {
        Explore(edges, next, visited, path, false);
      }
    } else if (visited.find(node) == visited.end()) {
      visited.insert(node);
      for (const auto& next: edges[node]) {
        Explore(edges, next, visited, path, re_enter);
      }
      visited.erase(node);
    }
  } else {
    for (const auto& next: edges[node]) {
      Explore(edges, next, visited, path, re_enter);
    }
  }
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

  for (const auto& next: edges["start"]) {
    Explore(edges, next, visited, path);
  }

  std::cout << path << '\n';
}

