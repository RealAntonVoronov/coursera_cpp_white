#include "string"
#include "vector"
#include "algorithm"

class SortedStrings{
public:
    void AddString(const std::string& s){
        strings.push_back(s);
    }
    std::vector<std::string> GetSortedStrings(){
        std::sort(std::begin(strings), std::end(strings));
        return strings;
    }
private:
    std::vector<std::string> strings;
};