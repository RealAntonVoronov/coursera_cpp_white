#include "iostream"
#include "vector"

int main() {
    int n, avg;
    std::cin >> n;
    std::vector<int> temp_stats(n), res_days;

    for (int i=0; i<temp_stats.size();++i){
        std::cin >> temp_stats[i];
        avg += temp_stats[i];
    }
    avg /= n;

    for (int i=0; i<temp_stats.size();++i){
        if (temp_stats[i] > avg) {
            res_days.push_back(i);
        }
    }

    std::cout << res_days.size() << std::endl;
    for (int& x : res_days){
        std::cout << x << " ";
    }
    return 0;
}