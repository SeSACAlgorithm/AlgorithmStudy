#include <iostream>
#include <algorithm>

using namespace std;

int n;
int score[300];
int dp[300];

void Input()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> score[i];
}

void Solve()
{
    dp[0] = score[0];
    dp[1] = score[0] + score[1];
    dp[2] = max(score[0], score[1]) + score[2];

    for(int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i-3] + score[i-1], dp[i-2]) + score[i];
    }

    cout << dp[n-1];
}

int main(void)
{
    Input();
    Solve();
}