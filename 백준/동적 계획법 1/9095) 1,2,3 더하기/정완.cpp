/*
n = 1
    output = 1

n = 2       1+1 // 2
    output = 2

n = 3       1+1+1 // 1+2 // 2+1 // 3 //
    output = 4

n = 4       1+1+1+1 // 1+1+2 // 1+2+1 // 2+1+1 // 2+2 // 1+3 // 3+1 //
    output = 7

n = 5       1+1+1+1+1 // 1+1+1+2 // 1+1+2+1 // 1+2+1+1 // 2+1+1+1// 1+2+2 // 2+1+2 // 2+2+1 // 1+1+3 // 1+3+1 // 3+1+1 // 3+2 // 2+3
    output = 13

dp[n] = d[n-1] + d[n-2] + d[n-3]
*/


#include "iostream"

using namespace std;

int dp[12];

int solve(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=4; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    return dp[n];
}

int main(void)
{
    int T, n;
    cin >> T;

    for(int i=0; i<T; i++)
    {
        cin >> n;
        cout << solve(n) << "\n";
    }
}