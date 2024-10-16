#include <iostream>
using namespace std;
int dp[1002];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[n - 1];
    
    return 0;
}
