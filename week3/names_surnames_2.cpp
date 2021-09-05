#include "string"
#include "map"
#include "vector"

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
std::vector<std::string> GetAllNames(const std::map<int, std::string>& history, const int& year){
    std::vector<std::string> names;
    for (const auto& x : history){
        if (x.first <= year){
            names.push_back(x.second);
        }
        else break;
    }
    return names;
}

std::string PrintAnswer(std::string first_name, std::string last_name){
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
std::string PrintNames(const std::vector<std::string>& names){
    int n = names.size();
    std::vector<std::string> result = {names[n-1]};
    std::string prev_name = names[n - 1];
    if (n > 1){
        for (int i = n - 2; i >= 0; i--){
            std::string name = names[i];
            if (name != prev_name){
                result.push_back(name);
                prev_name = name;
            }
            else continue;
        }
    }
    std::string ans;
    if (result.size() == 1){
        return result[0];
    }
    else{
        ans = result[0] + " (";
        int n = result.size();
        for (int i = 1; i < n - 1; ++i){
            ans += result[i] + ", ";
        }
        ans += result[n-1] + ")";
    }
    return ans;
}
std::string PrintAnswerWithHistory(std::vector<std::string> all_names, std::vector<std::string> all_surnames){
    if (all_names.empty() && all_surnames.empty()){
        return "Incognito";
    }
    else if (all_names.empty()){
        return PrintNames(all_surnames) + " with unknown first name";
    }
    else if (all_surnames.empty()){
        return PrintNames(all_names) + " with unknown last name";
    }
    else return PrintNames(all_names) + " " + PrintNames(all_surnames);
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

        return PrintAnswer(first_name, last_name);
    }
    std::string GetFullNameWithHistory(const int& year){
        std::string result;
        std::vector<std::string> all_names={}, all_surnames={};
        all_names = GetAllNames(name_history, year);
        all_surnames = GetAllNames(surname_history, year);

        return PrintAnswerWithHistory(all_names, all_surnames);
    }
private:
    std::map<int, std::string> name_history, surname_history;
};