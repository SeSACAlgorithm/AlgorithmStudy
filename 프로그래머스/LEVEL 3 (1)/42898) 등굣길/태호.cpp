#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, 0));

    for (const auto& puddle : puddles)
        visited[puddle[1]][puddle[0]] = true;

    dp[1][1] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!visited[i][j])
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
    

    return dp[n][m];
}
