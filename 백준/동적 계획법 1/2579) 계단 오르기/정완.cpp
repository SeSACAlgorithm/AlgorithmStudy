/*
arr[1] = 10
arr[2] = 20
arr[3] = 15
arr[4] = 25
arr[5] = 10
arr[6] = 20
*/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n;
vector<int> arr;  // 각 계단 값
vector<int> dp;   // 최대 합

void input()
{
    cin >> n;

    arr.resize(n, 0);
    dp.resize(n, 0);

    for(int i=0; i<n; i++)
        cin >> arr[i];
}

void solution()
{
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for (int i = 3; i < n; i++)
        dp[i] = max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);     // 전 단계에서 2번 연속 되었는가? or 아닌가?
}

void solve()
{
    input();
    solution();

    cout << dp[n-1] << "\n";
}

int main()
{
    solve();

    return 0;
}