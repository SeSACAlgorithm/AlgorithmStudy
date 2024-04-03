#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int len = computers.size();
    
    vector<bool> visited(computers.size(), false);
    queue<int> que;
    
    int cur = 0;
    for(int idx = 0; idx < len; idx++)
    {
        if(visited[idx]) continue;
        
        for(int i = 0; i < len; i++)
        {
            if(idx == i) continue;
            if(computers[idx][i] == 0) continue;

            que.push(i);
            visited[i] = true;
        }

        while(false == que.empty())
        {
            cur = que.front();
            que.pop();

            for(int i = 0; i < len; i++)
            {
                if(cur == i) continue;
                if(computers[cur][i] == 0) continue;
                if(visited[i]) continue;

                que.push(i);
                visited[i] = true;
            }
        }
        answer++;
    }
    
    return answer;
}