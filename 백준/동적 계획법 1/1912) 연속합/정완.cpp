#include "iostream"
#include "algorithm"

using namespace std;

int n;

int sum[100001], dp[100001];

void Input()
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> sum[i];

        dp[i] = sum[i];
    }
}

void Solution()
{
    int maxSum = dp[0];

    for(int i=1; i<n; i++)
    {
        dp[i] = max(dp[i], dp[i-1] + sum[i]);

        if(dp[i] > maxSum)
            maxSum = dp[i];
    }

    cout << maxSum;
}

int main()
{
    Input();
    Solution();
}