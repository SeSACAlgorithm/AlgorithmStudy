#define MAX 5000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> v;

int dp[21][2];

void Initialize()
{
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = MAX + 1;
        dp[i][1] = MAX + 1;
    }
}

void Input()
{
    cin >> n;

    v.push_back({0, 0});
    int sj, bj;
    for(int i = 0; i < n-1; i++)
    {
        cin >> sj >> bj;
        v.push_back({sj, bj});
    }
    cin >> k;
}

void Solve()
{
    dp[1][0] = 0;
    dp[2][0] = v[1].first;
    dp[3][0] = min(v[1].second, v[1].first + v[2].first);

    for(int i = 4; i <= n; i++)
    {
        dp[i][0] = min(v[i-2].second + dp[i-2][0], v[i-1].first + dp[i-1][0]);
        
        dp[i][1] = min(v[i-1].first + dp[i-1][1], v[i-2].second + dp[i-2][1]);
        dp[i][1] = min(dp[i][1], k + dp[i-3][0]);
    }

    cout << min(dp[n][0], dp[n][1]);
}

int main(void)
{
    Input();
    Initialize();
    Solve();
}