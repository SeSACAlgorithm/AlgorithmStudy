#include <vector>
#include <algorithm>

using namespace std;

int get_max(vector<int>& nums, int idx)
{
    int max = 0;
    for(int i = 0; i < 4; ++i)
    {
        if(i == idx) continue;
        if(max < nums[i]) max = nums[i];
    }
    return max;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    vector<vector<int>> DP(land.size(), vector<int>(4, 0));
    for(int i = 0; i < 4; ++i)
        DP[0][i] = land[0][i];
    
    for(int i = 1; i < land.size(); ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            DP[i][j] = land[i][j] + get_max(DP[i - 1], j);
        }
    }
    
    return *max_element(DP.back().begin(), DP.back().end());
}