#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> num(N);
    for (int i = 0; i < N; ++i)
        cin >> num[i];

    // 부분 합 구하기
    vector<int> sum(N + 1);
    for (int i = 1; i <= N; ++i)
        sum[i] = sum[i - 1] + num[i - 1];

    // x1* x2 + x1 * x3 + ... = x1 * (x2 + x3 + ...)
    // 따라서 a번째 원소 * (b부터 마지막까지의 합)으로 계산할 수 있음 
    long long answer = 0;
    for(int i = 0; i < N - 1; ++i)
        answer += num[i] * (sum.back() - sum[i + 1]);

    cout << answer;
}