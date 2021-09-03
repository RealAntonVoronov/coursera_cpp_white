#include "map"
#include "iostream"
#include "string"
#include "set"

int main() {
    int num_queries, n_stops;
    std::string stop;
    std::cin >> num_queries;
    std::map<std::set<std::string>, int> all_routes;

    for (int i = 0; i < num_queries; i++){
        std::cin >> n_stops;
        std::set<std::string> route;
        for (int j = 0; j < n_stops; j++){
            std::cin >> stop;
            route.insert(stop);
        }
        if (all_routes.count(route) == 0){
            int new_number = all_routes.size() + 1;
            all_routes[route] = new_number;
            std::cout << "New bus " << new_number;
        }
        else{
            std::cout << "Already exists for " << all_routes[route];
        }
        std::cout << std::endl;
    }

    return 0;
}