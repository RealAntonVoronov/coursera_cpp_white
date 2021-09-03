#include "string"

bool IsPalindrom(std::string x){
    for (int i=0; i < x.size()/2; ++i){
        if (x[i] != x[x.size() - 1 - i]){
            return false;
        }
    }
    return true;
}