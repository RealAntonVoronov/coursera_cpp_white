#include "string"
#include "vector"
#include "iostream"

bool Valid(const int& k, const int& n){
    return (k >= 1 && k <= n);
}

struct Student{
    std::string name, surname;
    int birth_day, birth_month, birth_year;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        Student cur_student;
        std::cin >> cur_student.name >> cur_student.surname;
        std::cin >> cur_student.birth_day >> cur_student.birth_month >> cur_student.birth_year;
        students[i] = cur_student;
    }
    int num_queries;
    std::cin >> num_queries;
    for (int i = 0; i < num_queries; i++) {
        std::string query;
        int k=0;
        std::cin >> query >> k;
        if (query == "name") {
            if (Valid(k, n)) {
                std::cout << students[k - 1].name << " " << students[k - 1].surname << "\n";
            } else std::cout << "bad request\n";
        } else if (query == "date") {
            if (Valid(k, n)) {
                std::cout << students[k - 1].birth_day << "." << students[k - 1].birth_month << "."
                          << students[k - 1].birth_year << "\n";
            } else std::cout << "bad request\n";
        } else std::cout << "bad request\n";
    }
    return 0;
}