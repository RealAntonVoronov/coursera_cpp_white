#include <iostream>
#include "numeric"
#include "sstream"
#include "set"
#include "vector"
#include "map"
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        int gcd = std::gcd(numerator, denominator);
        p = numerator / gcd;
        q = denominator / gcd;
        if (denominator < 0){
            p *= -1;
            q *= -1;
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

bool operator == (const Rational& lhs, const Rational& rhs){
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator + (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            rhs.Denominator() * lhs.Denominator()};
}

Rational operator - (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            rhs.Denominator() * lhs.Denominator()};
}

Rational operator * (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator / (const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
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

bool operator < (const Rational& lhs, const Rational& rhs){
    return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
