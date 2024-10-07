#include <iostream>

using namespace std;

long long n, result;
long long dp[100001];
long long arr[100001];

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    dp[0] = arr[0] > 0 ? arr[0] : 0;
    result = arr[0];

    for (int i = 1; i < n; ++i)
    {
        long long num = dp[i - 1] + arr[i];
        
        result = max(result, num);

        if(num >= 0)
            dp[i] = num;
    }

    cout << result;

    return 0;
}
