//wap to find a prime factor of number

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout<<"Enter a number :"<<endl;
    cin >> n;

    cout << "The prime factors of " << n << " are: ";

    // Find the prime factors
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If the number is greater than 1, it is a prime factor
    if (n > 1) {
        cout << n;
    }

    cout << endl;

    return 0;
}

