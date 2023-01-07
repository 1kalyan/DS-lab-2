//wap to implement the concept of linear congrugence.

#include <iostream>
using namespace std;
// Function to find the smallest positive integer solution
// of the linear congruence ax ≡ b (mod m)
int linear_congruence(int a, int b, int m)
{
    // we are looking for a solution of the form x ≡ y (mod m)
    // where y is the remainder when b is divided by m

    int y = b % m;

    // now we need to find the smallest positive integer solution
    // of the equation ax ≡ y (mod m)
    for (int x = 0; x < m; x++)
        if ((a * x) % m == y)
            return x;

    // if no solution is found, return -1
    return -1;
}

int main()
{
    int a, b, m;
    cout<<"Enter a value of a,b,m in term of ax=b(mod m)"<<endl;
    // read the values of a, b, and m
    cin >> a >> b >> m;

    int x = linear_congruence(a, b, m);

    // print the solution
    cout << "x ≡ " << x << " (mod " << m << ")" <<endl;

    return 0;
}
