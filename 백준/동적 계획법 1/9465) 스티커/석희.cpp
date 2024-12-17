#include <iostream>
#include <algorithm>

using namespace std;

int T, n;
int stickers[2][100000];
int dp[2][100000];

void Input()
{
    cin >> n;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> stickers[i][j];
            dp[i][j] = 0;
        }
    }
}

void Solve()
{
    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];
    dp[0][1] = dp[1][0] + stickers[0][1];
    dp[1][1] = dp[0][0] + stickers[1][1];

    for(int i = 2; i < n; i++)
    {
        dp[0][i] = stickers[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = stickers[1][i] + max(dp[0][i-1], dp[0][i-2]);
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
}

int main(void)
{
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        Input();
        Solve();
    }
}