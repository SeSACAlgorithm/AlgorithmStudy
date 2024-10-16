#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int n;
int d[305];
int a[305];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    d[1] = a[1];

    if (n > 1)
        d[2] = a[1] + a[2];

    if (n > 2)
        d[3] = a[3] + max(a[1], a[2]);


    for (int i = 4; i <= n; ++i)
    {
        d[i] = a[i] + max(a[i - 1] + d[i - 3], d[i - 2]);
    }

    cout << d[n];

    return 0;
}

