// 던전마다 탐험을 시작하기 위해 필요한 "최소 필요 피로도"
// 던전 탐험 마치면 소모되는 "소모 피로도"
// 현재 피로도 k

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
    do
    {
        int temp_k = k;
        int temp_answer = 0;
        for(int i = 0; i < dungeons.size(); i++)
        {
            if(temp_k >= dungeons[i][0])
            {
                temp_k -= dungeons[i][1];
                temp_answer++;
            }
        }
        answer = max(answer, temp_answer);
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}