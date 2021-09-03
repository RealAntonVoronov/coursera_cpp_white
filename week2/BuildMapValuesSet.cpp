#include "map"
#include "set"
#include "string"

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m){
    std::set<std::string> res;
    for (const auto& x : m){
        res.insert(x.second);
    }

    return res;
}