#include "map"
#include "iostream"
#include "string"

int main(){
    int num_queries;
    std::cin >> num_queries;
    std::map<std::string, std::string> capitals_dict;

    for (int i = 0; i < num_queries; i++){
        std::string query;
        std::cin >> query;
        if (query == "CHANGE_CAPITAL"){
            std::string country, new_capital, current_capital;
            std::cin >> country >> new_capital;

            if (capitals_dict.count(country) == 0){
                std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;
            }
            else {
                current_capital = capitals_dict[country];
                if (current_capital == new_capital){
                    std::cout << "Country " << country << " hasn't changed its capital\n";
                }
                else std::cout << "Country " << country << " has changed its capital from "
                               << current_capital << " to " << new_capital << std::endl;
            }
            capitals_dict[country] = new_capital;
        }
        else if (query == "RENAME"){
            std::string old_country_name, new_country_name;
            std::cin >> old_country_name >> new_country_name;
            if (capitals_dict.count(old_country_name) == 0 || capitals_dict.count(new_country_name) != 0
                || old_country_name == new_country_name){
                std::cout << "Incorrect rename, skip\n";
            }
            else {
                std::cout << "Country " << old_country_name << " with capital " << capitals_dict[old_country_name]
                          << " has been renamed to " << new_country_name << std::endl;
                capitals_dict[new_country_name] = capitals_dict[old_country_name];
                capitals_dict.erase(old_country_name);
            }
        }
        else if (query == "ABOUT"){
            std::string country;
            std::cin >> country;
            if (capitals_dict.count(country) == 0){
                std::cout << "Country " << country << " doesn't exist\n";
            }
            else std::cout << "Country " << country << " has capital " << capitals_dict[country] << std::endl;
        }
        else if (query == "DUMP"){
            if (capitals_dict.size() == 0){
                std::cout << "There are no countries in the world";
            }
            else {
                for (auto item: capitals_dict) {
                    std::cout << item.first << "/" << item.second << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}