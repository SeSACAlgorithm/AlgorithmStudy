#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> times(N + 1);
    vector<int> pays(N + 1);
    for(int i = 1; i <= N; ++i)
        cin >> times[i] >> pays[i];

    vector<int> DP(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        // 이전까지 갱신한 최대값보다 작다면 갱신
        if (DP[i] < DP[i - 1])
            DP[i] = DP[i - 1];
        // 현재 업무를 수행할 수 있는 경우,
        // 계산된 최대값 vs 현재 업무 수행 시의 최대값 중 큰 값 선택
        if(i + times[i] - 1 <= N)
            DP[i + times[i] - 1] = max(DP[i + times[i] - 1], DP[i - 1] + pays[i]);
    }

    cout << DP.back();
}