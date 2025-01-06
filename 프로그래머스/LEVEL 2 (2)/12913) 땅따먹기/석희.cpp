#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i = 0; i < 4; i++) dp[0][i] = land[0][i];

    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int maxLast = 0;
            for(int k = 0; k < 4; k++)
            {
                // 같은 열이라면 넘어가기
                if(j == k) continue;
                
                // 바로 전행에 있는 값들 중 제일 큰 값 찾기
                maxLast = max(dp[i-1][k], maxLast);  
            }
            // 현재 모든 행에 전행의 최대값 더해주기
            dp[i][j] = land[i][j] + maxLast;
        }
    }
    
    for(int i = 0; i < 4; i++) answer = max(dp[land.size()-1][i], answer);
    return answer;
}