#include "string"
#include "algorithm"

class ReversibleString{
public:
    ReversibleString(){}
    ReversibleString(const std::string& s){
        data = s;
    }
    void Reverse(){
        std::reverse(std::begin(data), end(data));
    }
    std::string ToString() const{
        return data;
    }
private:
    std::string data;
};