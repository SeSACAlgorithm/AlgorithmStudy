#include <iostream>

using namespace std;

int gcd(int n, int m)
{
    int r;
    r = n % m;
    while (r != 0)
    {
        n = m;
        m = r;
        r = n % m;
    }
    return m;
}

int main() {
    int a, b, g;
    cin >> a >> b;
    g = gcd(a, b);
    cout << g << "\n" << a * b / g;

    return 0;
}