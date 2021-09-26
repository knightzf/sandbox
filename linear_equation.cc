#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

/*
a = b + c + 2
b = c + 4
c = d + 1
d = 2
*/
using Map = std::unordered_map<char, std::unordered_set<char>>;

void solve() {
    Map dep = {
        {'a', {'b', 'c'}},
        {'b', {'c'}},
        {'c', {'d'}},
    };
    Map contrib = {
        {'b', {'a'}},
        {'c', {'a', 'b'}},
        {'d', {'c'}},
    };
    std::unordered_map<char, int> values = {
        {'a', 2},
        {'b', 4},
        {'c', 1},
        {'d', 2},
    };
    std::queue<char> solved_values;
    for(char c : {'a', 'b', 'c', 'd'}) {
        if(dep.count(c) == 0) solved_values.push(c);
    }
    while(!solved_values.empty()) {
        char c = solved_values.front();
        solved_values.pop();
        if(auto iter = contrib.find(c); iter != contrib.end()) {
            for(char x : iter->second) {
                if(auto jter = dep.find(x); jter != dep.end()) {                   
                    values[x] += values[c];
                    jter->second.erase(c);
                    if(jter->second.empty()) {
                        solved_values.push(x);
                    }
                }
            }
        }
    }
    for(auto [x, y] : values) {
        std::cout<< x << " " << y << std::endl;
    }
}

int main() {
    solve();
}