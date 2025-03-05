#include <iostream>
using namespace std;

// Function to calculate nth Catalan number
unsigned long long catalan(int n) {
    if (n == 0 || n == 1) return 1;

    unsigned long long C[n + 1];
    C[0] = C[1] = 1;

    for (int i = 2; i <= n; i++) {
        C[i] = 0;
        for (int j = 0; j < i; j++) {
            C[i] += C[j] * C[i - j - 1];
        }
    }
    return C[n];
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "1. Number of valid parenthesis expressions with " << N << " pairs: " << catalan(N) << endl;
    cout << "2. Number of ways to completely parenthesize " << N + 1 << " factors: " << catalan(N) << endl;
    cout << "3. Number of rooted binary trees with " << N << " internal nodes: " << catalan(N) << endl;
    cout << "4. Count of structurally unique BSTs with " << N << " keys: " << catalan(N) << endl;
    cout << "5. Count of ways to divide a circle using " << N << " non-intersecting chords: " << catalan(N) << endl;
    cout << "6. Number of paths in N*N matrix without crossing diagonal: " << catalan(N) << endl;

    return 0;
}
