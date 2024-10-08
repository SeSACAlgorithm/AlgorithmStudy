#include <iostream>
#include <algorithm>

using namespace std;


int n, t;
long long result = 0;
long long a[100005][2];
long long d[100005][2];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int j = 0; j < 2; ++j)
        {
            for (int i = 1; i <= n; ++i)
                cin >> a[i][j];
        }
        
        d[1][0] = a[1][0];
        d[1][1] = a[1][1];

        // 0,0 -> 1,0, 0,1 봉인
        // 0,1 -> 0,0, 0,2, 1,1 봉인
        for (int i = 2; i <= n; ++i)
        {
            d[i][0] = max({ d[i - 1][1], d[i - 2][1], d[i - 2][0] }) + a[i][0];
            d[i][1] = max({ d[i - 1][0], d[i - 2][1], d[i - 2][0] }) + a[i][1];
        }

        cout << max(d[n][0], d[n][1]) << '\n';
    }
}
