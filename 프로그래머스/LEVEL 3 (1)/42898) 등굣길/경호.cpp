#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int row = n, col = m;
    int div_val = 1000000007;
    
    vector<vector<int>> DP(row, vector<int>(col, 0));
    for(vector vec : puddles)
        DP[vec[1] - 1][vec[0] - 1] = -1;
    
    for(int i = 0; i < col; ++i)
    {
        if(DP[0][i] == -1) break;
        DP[0][i] = 1;
    }
    for(int i = 0; i < row; ++i)
    {
        if(DP[i][0] == -1) break;
        DP[i][0] = 1;
    }
    
    for(int i = 1; i < row; ++i)
    {
        for(int j = 1; j < col; ++j)
        {
            if(DP[i][j] == -1) continue;
            
            // upper
            if(DP[i - 1][j] > -1)
                DP[i][j] += DP[i - 1][j];
            
            // left
            if(DP[i][j - 1] > -1)
                DP[i][j] += DP[i][j - 1];
            
            if(DP[i][j] > div_val)
                DP[i][j] %= div_val;
        }
    }
    
    return DP[row - 1][col - 1];
}