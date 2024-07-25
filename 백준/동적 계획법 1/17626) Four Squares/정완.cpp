#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);

    dp[1] = 1;
  
    for(int i = 2; i <= n; i++)
    {
        int cnt = 300;

        for(int j = 1; j*j <= i; j++)
        {
            int a = i - j*j;
            cnt = min(cnt, dp[a]);
        }

        dp[i] = cnt + 1;
    }

    cout << dp[n];
}