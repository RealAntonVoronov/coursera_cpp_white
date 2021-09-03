#include "vector"
#include "string"
#include "iostream"


int main(){
    int q, cur_month=0;
    std::cin >> q;
    std::vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::vector<std::string>> monthly_tasks(days_in_month[cur_month]);

    for (int i = 0; i < q; i++){
        std::string command;
        std::cin >> command;

        if (command == "NEXT"){
            //PrintVector(monthly_tasks);
            int next_month = (cur_month + 1) % 12;

            if (days_in_month[next_month] < days_in_month[cur_month]){
                int last_day = days_in_month[next_month] - 1;

                for(int day = days_in_month[cur_month] - 1; day > last_day; day--) {
                    for (const std::string& task: monthly_tasks[day]) {
                        monthly_tasks[last_day].push_back(task);
                    }
                }
            }
            monthly_tasks.resize(days_in_month[next_month]);
            cur_month = next_month;
        }
        else if (command == "DUMP"){
            int day;
            std::cin >> day;
            std::vector<std::string>& tasks = monthly_tasks[day - 1];
            std::cout << tasks.size() << " ";

            for (const std::string& task : tasks){
                std::cout << task << " ";
            }
            std::cout << std::endl;
        }
        else if (command == "ADD"){
            int day;
            std::string task;
            std::cin >> day >> task;
            monthly_tasks[day - 1].push_back(task);
        }
    }
    return 0;
}