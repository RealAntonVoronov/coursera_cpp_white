#include "string"
#include "map"

std::string GetName(const std::map<int, std::string>& history, const int& year){
    std::string name;
    for (const auto& x : history){
        if (x.first > year){
            break;
        }
        name = x.second;
    }
    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        name_history[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        surname_history[year] = last_name;
    }
    std::string GetFullName(int year) {
        std::string first_name, last_name;
        first_name = GetName(name_history, year);
        last_name = GetName(surname_history, year);
        if (first_name.empty() && last_name.empty()){
            return "Incognito";
        }
        else if (first_name.empty()){
            return last_name + " with unknown first name";
        }
        else if (last_name.empty()){
            return first_name + " with unknown last name";
        }
        else return first_name + " " + last_name;
    }
    }
private:
    std::map<int, std::string> name_history, surname_history;
};