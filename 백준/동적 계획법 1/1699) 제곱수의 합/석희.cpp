#define MAX 100000
#include <iostream>

using namespace std;

int N;
int dp[MAX + 1];

void Solve()
{
    for(int i = 1; i <= N; i++) dp[i] = i;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    cout << dp[N];
}

int main(void)
{
    cin >> N;
    Solve();
}
