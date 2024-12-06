#include <iostream>

using namespace std;

int n;
int nums[500][500];
int dp[500][500];

void Input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> nums[i][j];
        }
    }
}

void Solve()
{
    dp[0][0] = nums[0][0];
    int answer = dp[0][0];
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) dp[i][j] = dp[i-1][j];
            else if(j == n - 1) dp[i][j] = dp[i-1][i-1];
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);

            dp[i][j] += nums[i][j];
            answer = max(dp[i][j], answer);
        }
    }

    cout << answer;
}

int main(void)
{
    Input();
    Solve();
}