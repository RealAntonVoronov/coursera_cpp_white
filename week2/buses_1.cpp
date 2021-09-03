#include "map"
#include "iostream"
#include "string"
#include "vector"

int main(){
    int num_queries;
    std::cin >> num_queries;
    std::map<std::string, std::vector<std::string>> all_buses;
    std::map<std::string, std::vector<std::string>> buses_for_stop;

    for (int i = 0; i < num_queries; i++) {
        std::string query;
        std::cin >> query;

        if (query == "NEW_BUS"){
            std::string bus;
            int num_stops;

            std::cin >> bus >> num_stops;
            for (int j = 0; j < num_stops; j++){
                std::string stop;
                std::cin >> stop;
                all_buses[bus].push_back(stop);
                buses_for_stop[stop].push_back(bus);
            }
        }
        else if (query == "BUSES_FOR_STOP"){
            std::string stop;
            std::cin >> stop;

            if (buses_for_stop.count(stop) == 0){
                std::cout << "No stop";
            }
            else {
                std::vector<std::string> buses = buses_for_stop[stop];
                for (const auto &bus: buses) {
                    std::cout << bus << " ";
                }
            }
            std::cout << std::endl;
        }
        else if (query == "STOPS_FOR_BUS"){
            std::string bus;
            std::cin >> bus;
            if (all_buses.count(bus) == 0){
                std::cout << "No bus\n";
            }
            else {
                for (const auto &stop: all_buses[bus]) {
                    std::cout << "Stop " << stop << ": ";
                    if (buses_for_stop[stop].size() == 1) {
                        std::cout << "no interchange\n";
                    }
                    else{
                        for (const auto &another_bus: buses_for_stop[stop]) {
                            if (another_bus != bus) {
                                std::cout << another_bus << " ";
                            }
                        }
                        std::cout << std::endl;
                    }
                }
            }
        }

        if (query == "ALL_BUSES"){
            if (all_buses.empty()){
                std::cout << "No buses\n";
            }
            else {
                for (const auto &item: all_buses) {
                    std::cout << "Bus " << item.first << ": ";
                    for (const auto &stop: item.second) {
                        std::cout << stop << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}