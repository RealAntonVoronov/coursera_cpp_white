#include "vector"

std::vector<int> Reversed(const std::vector<int>& v){
    std::vector<int> tmp;
    for (int i = v.size() - 1; i >= 0; i--){
        tmp.push_back(v[i]);
    }
    return tmp;
}