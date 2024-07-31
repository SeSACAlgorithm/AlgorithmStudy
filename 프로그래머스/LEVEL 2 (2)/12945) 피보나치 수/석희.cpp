#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int dp[100001];

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
    }
    return dp[n] % 1234567;
}