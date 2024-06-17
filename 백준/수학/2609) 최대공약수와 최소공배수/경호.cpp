#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int low = min(a, b);
    int high = max(a, b);

    int gcd = high % low;
    while(gcd > 0)
    {
        high = low;
        low = gcd;
        gcd = high % low;
    }
    gcd = low;

    int lcm = a * b / gcd;
    cout << gcd << endl << lcm;
}