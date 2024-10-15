#include <iostream>

using namespace std;
int n;
int d[20];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i < 11; ++i)
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    
    while (n--)
    {
        int x; cin >> x;
        cout << d[x] << '\n';
    }
}
