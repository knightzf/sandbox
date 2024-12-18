#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>

using namespace std;

std::unordered_map<std::string, std::unordered_map<std::string, double>> outmap;
std::unordered_map<std::string, std::unordered_map<std::string, double>> ownership;
double getOwnership(const std::string& a, const std::string& b) {
  if(!ownership[a].count(b)) {
    double val = 0;
    for(const auto& p : outmap[a]) {
      if(p.first == b) val += p.second;
      else {
        val += p.second * getOwnership(p.first, b);
      }
    }
    ownership[a][b] = val;
  }
  return ownership[a][b];
}

bool hasCycle(const std::string& node, std::unordered_map<std::string, bool>& visited,
  const std::unordered_map<std::string, std::unordered_map<std::string, double>>& outmap) {
  if(visited.count(node) && visited[node]) return true;
  visited[node] = true;
  if(outmap.count(node)) {
    for(const auto& p: outmap.at(node)) {
      if(hasCycle(p.first, visited, outmap)) return true;
    }  
  }
  return false;
}

int main() {
  std::unordered_map<std::string, std::unordered_map<std::string, double>> outmap;
  std::unordered_map<std::string, std::unordered_map<std::string, double>> inmap;
  std::unordered_set<std::string> nodes;
  for(;;) {
    std::string src, dest;
    double percent = 0.5;
    outmap[src][dest] += percent;
    inmap[dest][src] += percent;
    nodes.insert(src);
    nodes.insert(dest);
  }

  std::unordered_set<std::string> free;
  for(const auto& node : nodes) {
    if(inmap.count(node) == 0) {
      free.insert(node);
    }
  }

  while(!free.empty()) {
    auto node = *free.begin();
    free.erase(node);
    nodes.erase(node);
    if(outmap.count(node)) {
      for(const auto& p : outmap[node]) {
        inmap[p.first].erase(node);
        if(inmap[p.first].empty()) {
          free.insert(p.first);
          inmap.erase(p.first);
        }
      }
    }
  }

  return nodes.empty();
}
