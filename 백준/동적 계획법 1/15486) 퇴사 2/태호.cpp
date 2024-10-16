#include <iostream>
#include <algorithm>


using namespace std;
int n;

int t[1500005];
int a[1500005];
long long d[1500005];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> a[i];

    for (int i = n; i >= 1; --i)
    {
        if (t[i] + i <= n + 1)
        {
            d[i] = max(d[i + 1], d[i + t[i]] + a[i]);
        }
        else
        {
            d[i] = d[i - 1];
        }
    }

    cout << *max_element(d + 1, d + n + 1);
 

    return 0;
}

