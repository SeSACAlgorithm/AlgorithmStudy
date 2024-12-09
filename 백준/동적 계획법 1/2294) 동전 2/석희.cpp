#define MAX 10001

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coins[100];
int dp[MAX];

void Input()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    for(int i = 1; i <= k; i++)
    {
        dp[i] = MAX;
    }
}

void Solve()
{
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = coins[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j-coins[i]] + 1);
        }
    }

    if(dp[k] == MAX) cout << -1;
    else cout << dp[k];
}

int main(void)
{
    Input();
    Solve();
}