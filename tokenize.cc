#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> tokenizer(const std::string& str) {
    std::stringstream ss(str);
    std::vector<std::string> res;    
    for(std::string token; ss >> token; ) {
        res.push_back(token);
    }
    return res;
}


int main() {
    auto r = tokenizer("abc test -200.0");
    for(const auto& s : r) 
        std::cout<< s << std::endl;
}