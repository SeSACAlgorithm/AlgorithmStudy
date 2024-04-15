#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<bool>> connect(n + 1, vector<bool>(n + 1, false));
    for(vector<int> w : wires)
    {
        connect[w[0]][w[1]] = true;
        connect[w[1]][w[0]] = true;
    }
    
    for(vector<int> w : wires)
    {
        queue<int> que;
        vector<bool> visited(n + 1, false);
        que.push(w[0]);
        visited[w[0]] = true;
        visited[w[1]] = true;
        
        int count = 1;
        int cur = 0;
        while(false == que.empty())
        {
            cur = que.front();
            que.pop();
            
            for(int i = 1; i <= n; ++i)
            {
                if(connect[cur][i] && false == visited[i])
                {
                    visited[i] = true;
                    que.push(i);
                    ++count;
                }
            }
        }
        int res = abs(count * 2 - n);
        if(res < answer)
            answer = res;
    }
    
    return answer;
}