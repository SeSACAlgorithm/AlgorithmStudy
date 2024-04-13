#include <vector>

using namespace std;

void dfs(int count, int k, vector<vector<int>>& dungeons, vector<bool>& visited, int& result)
{       
    if(result < count)
        result = count;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visited[i]) continue;
        
        if(dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(count + 1, k - dungeons[i][1], dungeons, visited, result);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    dfs(0, k, dungeons, visited, answer);
    
    return answer;
}