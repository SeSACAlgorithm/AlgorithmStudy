#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // 초기값을 나올 수 없는 큰 값으로 설정
    vector<int> DP(n + 1, 10000);
    // 3킬로, 5킬로일때는 각각 1개의 봉지로 가능
    // n >= 6일 경우, n-3 킬로, n-5킬로 중 작은 값 + 1
    DP[3] = 1;
    DP[5] = 1;
    for (int i = 6; i <= n; ++i)
        DP[i] = min(DP[i - 3], DP[i - 5]) + 1;
    // DP[n]이 초기값 이상의 값이라면 불가능한 경우이므로 -1, 이외에는 DP[n] 출력
    if (DP[n] >= 10000)
        cout << -1;
    else
        cout << DP[n];
}