#include <iostream>

using namespace std;

int n;

int arr[100001];
long long sum[100001];

long long answer = 0;

int main(void)
{
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i = 1; i < n; i++)
    {
        answer += (sum[n] - sum[i]) * arr[i];
    }

    cout << answer << "\n";
}