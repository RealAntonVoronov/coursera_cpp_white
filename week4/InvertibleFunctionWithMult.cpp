#include "vector"
#include "algorithm"
#include "map"

class FunctionPart{
public:
    FunctionPart(char new_operation, double new_value){
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const{
        if (operation == '+'){
            return source_value + value;
        }
        else if (operation == '-') {
            return source_value - value;
        }
        else if (operation == '*'){
            return source_value * value;
        }
        else if (operation == '/'){
            return source_value / value;
        }
    }
    void Invert(){
        std::map<char, char> inverse_operations = {{'-', '+'},
                                                   {'+', '-'},
                                                   {'*', '/'},
                                                   {'/', '*'}};
        operation = inverse_operations[operation];
    }
private:
    char operation;
    double value;
};

class Function{
public:
    void AddPart(char operation, double value){
        parts.push_back({operation, value});
    }
    double Apply(double source_value) const{
        for (const FunctionPart& part : parts){
            source_value = part.Apply(source_value);
        }
        return source_value;
    }
    void Invert(){
        for (FunctionPart& part : parts){
            part.Invert();
        }
        std::reverse(std::begin(parts), std::end(parts));
    }
private:
    std::vector<FunctionPart> parts;
};