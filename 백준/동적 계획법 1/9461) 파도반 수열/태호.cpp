#include <iostream>

using namespace std;

long long n, num;
long long dp[101];

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= 100; ++i)
        dp[i] = dp[i - 3] + dp[i - 2];

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        cout << dp[num] << '\n';
    }

    return 0;
}
