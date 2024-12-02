#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int dp[100000];

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int answer = dp[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
        answer = max(answer, dp[i]);
    }
    cout << answer;
}   