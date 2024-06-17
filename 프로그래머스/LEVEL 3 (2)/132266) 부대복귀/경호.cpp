#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size(), -1);
    int limit = 500001;
    
    map<int, vector<int>> connected;
    for(vector<int> v : roads)
    {
        connected[v[0]].emplace_back(v[1]);
        connected[v[1]].emplace_back(v[0]);
    }
    
    queue<pair<int, int>> que;
    que.push(pair<int, int>{destination, 1});
    
    vector<int> dist(n + 1, -1);
    dist[destination] = 0;
    vector<bool> visited(n + 1, false);
    visited[destination] = true;
    
    int cur = 0, len = 0;
    while(false == que.empty())
    {
        cur = que.front().first;
        len = que.front().second;
        que.pop();
        
        if(connected[cur].empty()) continue;
        
        for(int loc : connected[cur])
        {
            if(visited[loc]) continue;
            
            dist[loc] = len;
            que.push(pair<int, int>{loc, len + 1});
            visited[loc] = true;
        }
    }
    
    for(int i = 0; i < sources.size(); ++i)
        answer[i] = dist[sources[i]];
    
    return answer;
}