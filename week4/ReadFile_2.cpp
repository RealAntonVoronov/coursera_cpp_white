#include "iostream"
#include "fstream"
#include "string"

int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    if (input.is_open()){
        std::string line;
        while(std::getline(input, line)){
            output << line << '\n';
        }
    }
    return 0;
}