#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<long long> answer(N);
    for(int i = 0; i < N; ++i)
    {
        long long a, b;
        cin >> a >> b;

        long long big = max(a, b);
        long long small = min(a, b);
        // 유클리드 호제법
        // 큰 수를 작은 수로 나누어 떨어질때까지 나누기
        // 매 시행 후 큰 수는 작은 수로, 작은 수는 나머지로 갱신
        while(small > 0)
        {
            int c = big % small;
            big = small;
            small = c;
        }

        answer[i] = a * b / big;
    }

    for (const long long& ans : answer)
        cout << ans << "\n";
}