#include <iostream>
#include "numeric"
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        } else {
            int gcd = std::gcd(numerator, denominator);
            p = numerator / gcd;
            q = denominator / gcd;
            if (denominator < 0) {
                p *= -1;
                q *= -1;
            }
        }
    }
    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;
};
Rational operator * (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}
Rational operator / (const Rational& lhs, const Rational& rhs){
    if (rhs.Numerator() == 0){
        throw domain_error("Division by zero");
    }
    else return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}
Rational operator + (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            rhs.Denominator() * lhs.Denominator()};
}
Rational operator - (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            rhs.Denominator() * lhs.Denominator()};
}
istream& operator >> (istream& input, Rational& rational){
    int p, q;
    if (input >> p){
        char sep;
        input >> sep;
        if (sep == '/'){
            if(input >> q){
                rational = Rational(p, q);
                return input;
            }
        }
    }
    return input;
}
ostream& operator << (ostream& output, const Rational& rational){
    output << rational.Numerator() << "/" << rational.Denominator();
    return output;
}
int main(){
    char operation;
    Rational a, b;
    try{
        cin >> a >> operation >> b;
    }
    catch (invalid_argument& ex){
        cout << ex.what();
        return 0;
    }
    if (operation == '+'){
        cout << a + b;
    }
    else if (operation == '-'){
        cout << a - b;
    }
    else if (operation == '*'){
        cout << a * b;
    }
    else if (operation == '/'){
        try{
            cout << a / b;
        }
        catch (domain_error& ex){
            cout << ex.what();
        }
    }
    else cout << "Unknown operation\n";

    return 0;
}