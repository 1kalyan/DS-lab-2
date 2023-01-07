#include <iostream>
#include <cstdlib>
#include <numeric>

using namespace std;

// Finds the solution to the system of linear congruences:
// x ≡ a1 (mod m1)
// x ≡ a2 (mod m2)
// ...
// x ≡ an (mod mn)
// Returns -1 if the system has no solution.
int chinese_remainder_theorem(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i];
        int Mi_inv = -1; // Inverse of Mi modulo m[i]
        for (int j = 1; j < m[i]; j++) {
            if ((Mi * j) % m[i] == 1) {
                Mi_inv = j;
                break;
            }
        }
        if (Mi_inv == -1) {
            return -1; // No solution
        }
        x += (Mi * Mi_inv * a[i]) % M;
        x = x % M;
    }

    return x;
}

int main() {
    int n;
    cin >> n;

    int a[n], m[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> m[i];
    }

    int x = chinese_remainder_theorem(a, m, n);
    if (x == -1) {
        cout << "No solution" << endl;
    } else {
        cout << "The solution is x ≡ " << x << " (mod " << accumulate(m, m+n, 1, multiplies<int>()) << ")" << endl;
    }

    return 0;
}
