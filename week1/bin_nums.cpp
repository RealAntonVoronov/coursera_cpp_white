#include "iostream"
#include "vector"
using namespace std;


void print_vector(vector<int> vec) {
    for (int i = vec.size() - 1; i >= 0; i--){
        cout << vec[i];
    }
    cout << endl;
}


int main() {
    int n;
    vector<int> res;
    cin >> n;
    while (n > 0) {
        res.push_back(n % 2);
        n /= 2;
    }
    print_vector(res);
    return 0;
}
