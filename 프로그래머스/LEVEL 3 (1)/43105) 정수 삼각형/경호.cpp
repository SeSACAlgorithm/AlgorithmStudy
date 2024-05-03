#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> DP(triangle.size(), vector<int>());
    DP[0].push_back(triangle[0][0]);
    
    for(int i = 1; i < triangle.size(); ++i)
    {
        DP[i].push_back(DP[i - 1][0] + triangle[i][0]);
        for(int j = 1; j < triangle[i].size() - 1; ++j)
        {
            int bigger = max(DP[i - 1][j - 1], DP[i - 1][j]);
            DP[i].push_back(bigger + triangle[i][j]);
        }
        DP[i].push_back(DP[i - 1].back() + triangle[i].back());                 
    }
    
    return *max_element(DP.back().begin(), DP.back().end());
}