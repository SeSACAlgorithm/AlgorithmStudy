#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    
    for(int i = 0; i < roads.size(); ++i)
    {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({destination, 0});
    
    vector<int> d(n + 1, 1e9);
    d[destination] = 0;
    
    while(!pq.empty())
    {
        auto[cur, dist] = pq.top();
        pq.pop();
        
        if(dist != d[cur]) continue;
        
        for(int nxt : adj[cur])
        {
            if(d[nxt] > d[cur] + 1)
            {
                d[nxt] = d[cur] + 1;
                pq.push({nxt, d[nxt]});
            }
        }
    }
    
    for(int i = 0; i < sources.size(); ++i)
    {
        if(d[sources[i]] == 1e9)
            answer.push_back(-1);
        else
            answer.push_back(d[sources[i]]);
    }
    
    return answer;
}
