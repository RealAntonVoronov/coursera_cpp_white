#include "vector"
#include "iostream"
#include "string"
#include "algorithm"

int main(){
    int q;
    std::cin >> q;
    std::vector<int> queue;

    for(int i = 0; i < q; i++){
        std::string command;
        std::cin >> command;
        if (command != "WORRY_COUNT"){
            int k;
            std::cin >> k;
            if (command == "WORRY"){
                queue[k] = 1;
            }
            else if (command == "QUIET"){
                queue[k] = 0;
            }
            else if (command == "COME"){
                queue.resize(queue.size() + k, 0);
            }
        }
        else{
            std::cout << std::count(begin(queue), end(queue), 1) << std::endl;
        }
    }
    return 0;
}