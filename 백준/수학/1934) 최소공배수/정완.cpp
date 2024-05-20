#include "iostream"

using namespace std;

int gcd(int a, int b)
{
     int c = a % b;

    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n;
    cin >> n;

    int num1, num2;
    for(int i=0; i<n; i++)
    {
        cin >> num1 >> num2;

        cout << lcm(num1, num2) << '\n';
    }
}