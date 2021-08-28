#include "iostream"
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        int c = b;
        b = a;
        a = c;
    }
    while (a % b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    cout << b;
    return 0;
}
