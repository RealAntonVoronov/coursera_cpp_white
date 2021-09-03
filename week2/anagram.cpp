#include "map"
#include "iostream"
#include "string"

std::map<char, int> BuildWordMap(const std::string& word){
    std::map<char, int> result;
    for (char c : word){
        result[c]++;
    }
    return result;
}

int main(){
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        bool ans=true;
        std::string word_a, word_b;
        std::cin >> word_a >> word_b;
        std::map<char, int> word_a_counter, word_b_counter;
        word_a_counter = BuildWordMap(word_a);
        word_b_counter = BuildWordMap(word_b);

        if (word_a_counter == word_b_counter){
            std::cout << "YES\n";
        }
        else std::cout << "NO\n";
    }

    return 0;
}