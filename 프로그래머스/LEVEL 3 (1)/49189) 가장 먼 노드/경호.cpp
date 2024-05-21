#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    map<int, vector<int>> counts;
    vector<bool> visited(n + 1);
    
    map<int, vector<int>> connected;
    for(vector<int> v : edge)
    {
        connected[v[0]].emplace_back(v[1]);
        connected[v[1]].emplace_back(v[0]);
    }
    
    queue<pair<int, int>> que;
    que.push(pair<int, int>{1, 0});
    visited[1] = true;
    
    pair<int, int> cur;
    while(false == que.empty())
    {
        cur = que.front();
        que.pop();
        counts[cur.second].push_back(cur.first);
        
        for(int node :connected[cur.first])
        {
            if(false == visited[node])
            {
                que.push(pair<int, int>{node, cur.second + 1});
                visited[node] = true;
            }
        }
    }
    
    auto it = --counts.end();
    return (*it).second.size();
}