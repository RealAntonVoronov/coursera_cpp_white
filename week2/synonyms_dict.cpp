#include "map"
#include "set"
#include "string"
#include "iostream"

void PrintSet(const std::set<std::string>& s){
    for (const auto& x : s){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::map<std::string, std::set<std::string>> synonyms;
    int num_queries;
    std::cin >> num_queries;

    for (int i = 0; i < num_queries; i++){
        std::string query;
        std::cin >> query;

        if (query == "ADD"){
            std::string word_a, word_b;
            std::cin >> word_a >> word_b;
            synonyms[word_a].insert(word_b);
            synonyms[word_b].insert(word_a);
            /*std::cout << word_a << " synonyms: ";
            PrintSet(synonyms[word_a]);
            std::cout << word_b << " synonyms: ";
            PrintSet(synonyms[word_b]);*/
        }
        else if (query == "COUNT"){
            std::string word_a;
            std::cin >> word_a;
            std::cout << synonyms[word_a].size() << std::endl;
        }
        else if (query == "CHECK"){
            std::string word_a, word_b;
            std::cin >> word_a >> word_b;
            //PrintSet(synonyms[word_a]);
            if (synonyms[word_a].count(word_b) == 0){
                std::cout << "NO\n";
            }
            else std::cout << "YES\n";
        }

    }
    return 0;
}