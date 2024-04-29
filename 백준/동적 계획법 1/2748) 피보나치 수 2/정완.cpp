#include <iostream>

using namespace std;

long long Fibonacci[91];

int main()
{
    int n;
    cin >> n;

    Fibonacci[0] = 0;
    Fibonacci[1] = 1;

    for(int i=2; i<=n; i++)
        Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];

    cout << Fibonacci[n];
}