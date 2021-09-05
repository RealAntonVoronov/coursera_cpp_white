#include "algorithm"
#include "vector"
#include "iostream"
#include "string"


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (auto& x : v){
        std::cin >> x;
    }

    std::sort(std::begin(v), std::end(v), [](std::string x, std::string y) {
        for (auto& c : x){
            c = std::tolower(c);
        }
        for (auto& c : y){
            c = std::tolower(c);
        }
        return x < y;}
    );

    for (const auto& x : v){
        std::cout << x << " ";
    }

    return 0;
}