#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int left, right;
    vector<int> answer(N);
    for(int idx = 0; idx < N; ++idx)
    {
        cin >> left >> right;

        int limit = right - left + 1;
        vector<vector<int>> DP(left, vector<int>(right, 0));
        for(int i = 0; i < limit; ++i)
            DP[0][i] = 1;

        for (int i = 1; i < left; ++i)
            for (int j = i; j < right; ++j)
                DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];

        answer[idx] = accumulate(DP.back().begin(), DP.back().end(), 0);
    }

    for (const int& ans : answer)
        cout << ans << "\n";
}