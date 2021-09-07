#include "string"

struct Specialization{
    std::string value;
    explicit Specialization(const std::string& s){
        value = s;
    }
};
struct Course{
    std::string value;
    explicit Course(const std::string& s){
        value = s;
    }
};
struct Week{
    std::string value;
    explicit Week(const std::string& s){
        value = s;
    }
};
struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;
    LectureTitle(const Specialization& s, const Course& c, const Week& w){
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
};