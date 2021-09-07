#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"

int main(){
    std::ifstream input("input.txt");
    std::cout << std::fixed << std::setprecision(3);
    if (input.is_open()){
        double value=0;
        while(input >> value){
            std::cout << value << '\n';
        }
    }
    return 0;
}