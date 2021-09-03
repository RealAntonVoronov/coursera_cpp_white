#include "iostream"
#include "cmath"


int main() {
    double a, b, c;

    std::cin >> a >> b >> c;
    if (a == 0){
        if (b != 0){
            std::cout << -c/b;
        }
    }
    else if (b == 0){
        if (c == 0) std::cout << 0;
        else if (-c/a >= 0){
            std::cout << sqrt(-c/a) << " " << -sqrt(-c/a);
        }
    }
    else{
        double d = b*b - 4*a*c;
        if (d > 0){
            std::cout << (-b + sqrt(d))/2/a << " " << (-b - sqrt(d))/2/a;
        }
        else if (d == 0){
            std::cout << -b/2/a;
        }
    }

    return 0;
}
