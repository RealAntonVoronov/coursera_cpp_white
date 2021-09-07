#include "iostream"
#include "fstream"
#include "iomanip"
#include "vector"

int main(){
    std::ifstream input("input.txt");
    int n, m;
    input >> n >> m;
    std::vector<std::vector<int>> table(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int a;
            input >> a;
            input.ignore(1);
            table[i].push_back(a);
        }
        for (int j = 0; j < m; j++){
            std::cout << std::setw(10) << table[i][j];
            if (j != m - 1){
                std::cout << " ";
            }
        }
        if (i != n-1){
            std::cout << std::endl;
        }
    }

    return 0;
}