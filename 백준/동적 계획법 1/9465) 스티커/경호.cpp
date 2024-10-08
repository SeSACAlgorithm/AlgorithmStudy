#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    vector<int> answer(T);
    for(int idx = 0; idx < T; ++idx)
    {
        int N;
        cin >> N;

        vector<vector<int>> scores(N, vector<int>(2, 0));
        for (int i = 0; i < N; ++i)
            cin >> scores[i][0];
        for (int i = 0; i < N; ++i)
            cin >> scores[i][1];

        if (N < 2)
        {
            answer[idx] = max(scores[0][0], scores[0][1]);
            continue;
        }

        vector<vector<int>> DP(N, vector<int>(2, 0));
        DP[0][0] = scores[0][0];
        DP[0][1] = scores[0][1];
        DP[1][0] = DP[0][1] + scores[1][0];
        DP[1][1] = DP[0][0] + scores[1][1];

        for(int i = 2; i < N; ++i)
        {
            DP[i][0] = max(DP[i - 1][1], max(DP[i - 2][0], DP[i - 2][1])) + scores[i][0];
            DP[i][1] = max(DP[i - 1][0], max(DP[i - 2][0], DP[i - 2][1])) + scores[i][1];
        }
        answer[idx] = max(DP.back()[0], DP.back()[1]);
    }

    for (const int& ans : answer)
        cout << ans << "\n";
}