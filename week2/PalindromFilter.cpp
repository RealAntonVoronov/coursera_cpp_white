#include "vector"
#include "string"

bool IsPalindrom(std::string x){
    for (int i=0; i < x.size()/2; ++i){
        if (x[i] != x[x.size() - 1 - i]){
            return false;
        }
    }
    return true;
}


std::vector<std::string> PalindromFilter (std::vector<std::string> words, int minLength){
    std::vector<std::string> res = {};
    for (std::string s : words) {
        if (s.size() >= minLength && IsPalindrom(s)){
            res.push_back(s);
        }
    }
    return res;
}