#include <iostream>
#include <vector>

using namespace std;

int n;

void Solve()
{
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;
        for(int j = 1; j*j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    cout << dp[n];
}

int main(void)
{
    cin >> n;
    Solve();
}