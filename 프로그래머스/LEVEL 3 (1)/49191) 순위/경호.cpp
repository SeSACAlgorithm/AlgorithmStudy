#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    map<int, vector<int>> winners;
    map<int, vector<int>> losers;
    
    for(vector<int> v : results)
    {
        winners[v[1]].emplace_back(v[0]);
        losers[v[0]].emplace_back(v[1]);
    }
    
    for(int i = 1; i <= n; ++i)
    {
        int count = 0, cur = 0;
        vector<bool> checked(n + 1, false);
        
        queue<int> win_que;
        queue<int> lose_que;
        win_que.push(i);
        lose_que.push(i);
        checked[i] = true;
        
        
        while(false == win_que.empty())
        {
            cur = win_que.front();
            win_que.pop();
            
            if(winners[cur].empty()) continue;
            
            for(int w : winners[cur])
            {
                if(false == checked[w])
                {
                    win_que.push(w);
                    checked[w] = true;
                    ++count;
                }
            }
        }
        while(false == lose_que.empty())
        {
            cur = lose_que.front();
            lose_que.pop();
            
            if(losers[cur].empty()) continue;
            
            for(int w : losers[cur])
            {
                if(false == checked[w])
                {
                    lose_que.push(w);
                    checked[w] = true;
                    ++count;
                }
            }  
        }
        
        if(count == n - 1) ++answer;
    }
    
    return answer;
}