#include <iostream>

#define MAX 1001

using namespace std;

int n;
int arr[MAX];
int dp[MAX];

void Input()
{
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];
}

void Solution()
{
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        ans = max(dp[i], ans);
    }

    cout << ans + 1;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    Solve();

    return 0;
}