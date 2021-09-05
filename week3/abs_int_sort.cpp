#include "algorithm"
#include "vector"
#include "iostream"


int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto& x : v){
        std::cin >> x;
    }
    std::sort(std::begin(v), std::end(v), [](int x, int y) {return abs(x) < abs(y);});
    for (const auto& x : v){
        std::cout << x << " ";
    }

    return 0;
}