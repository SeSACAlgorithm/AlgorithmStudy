#include "iostream"

using namespace std;

int main()
{
    int n;
    int t[1001];

    cin >> n;

    t[1] = 1;
    t[2] = 2;

    for(int i=3; i<=n; i++)
        t[i] = (t[i-2] + t[i-1]) % 10007;

    cout << t[n];
}