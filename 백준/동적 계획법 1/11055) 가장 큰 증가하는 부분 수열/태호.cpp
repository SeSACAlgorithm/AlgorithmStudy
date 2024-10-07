#include <iostream>
#include <algorithm>

using namespace std;

long long n, result;
long long dp[1001];
long long arr[1001];

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);

    
    cout << *max_element(dp, dp + n);

    return 0;
}
