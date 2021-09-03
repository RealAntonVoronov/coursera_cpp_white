#include "set"
#include "iostream"
#include "string"

int main() {
    int num_strings;
    std::set<std::string> res;
    std::cin >> num_strings;

    for (int i = 0; i < num_strings; ++i){
        std::string cur_string;
        std::cin >> cur_string;

        res.insert(cur_string);
    }
    std::cout << res.size() << std::endl;

    return 0;
}