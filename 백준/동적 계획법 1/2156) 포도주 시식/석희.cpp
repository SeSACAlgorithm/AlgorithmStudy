#include <iostream>
#include <algorithm>

using namespace std;

int n;
int juice[10001];
int dp[10001];

void Input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> juice[i];
    }
}

void Solve()
{
    dp[0] = 0;
    dp[1] = juice[1];
    dp[2] = juice[1] + juice[2];
    
    for(int i = 3; i <= n; i++)
    {
        // i번째 잔과 i-1번째 잔을 마시는 경우 (O X O O)
        // i번째 잔만 마시는 경우 (O X O)
        // i번째 잔을 마시지 않는 경우 (O X)
        dp[i] = max(dp[i-3] + juice[i-1] + juice[i], max(dp[i-2] + juice[i], dp[i-1]));
    }
    cout << dp[n];
}

int main(void)
{
    Input();
    Solve();
}