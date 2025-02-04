#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n/i){
                factors.push_back(n / i);
            }
        }
    }
    for (int i=0;i<factors.size();i++) {
        cout << factors[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printFactors(n);
    return 0;
}
