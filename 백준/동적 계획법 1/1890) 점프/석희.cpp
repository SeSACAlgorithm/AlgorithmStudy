#define MAX 100
#include <iostream>

using namespace std;

int n;
int map[MAX][MAX];
long long dp[MAX][MAX];

void Input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
}

void Solve()
{
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int jump = map[i][j];
            if(jump == 0 || (i == n -1 && j == n - 1)) continue;

            if(i + jump < n) dp[i + jump][j] = dp[i+jump][j] + dp[i][j];
            if(j + jump < n) dp[i][j + jump] = dp[i][j+jump] + dp[i][j];
        }
    }

    cout << dp[n-1][n-1];
}

int main(void)
{
    Input();
    Solve();
}