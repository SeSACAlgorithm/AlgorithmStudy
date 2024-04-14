#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, int>> adj[52];
int dist[52];
bool vis[52];
int k;
set<int> S;

void dfs(int cur)
{
    for (auto nxt : adj[cur])
    {
        if (vis[nxt.first] || k < nxt.second + dist[cur]) continue;
        vis[nxt.first] = true;
        dist[nxt.first] = dist[cur] + nxt.second;
        dfs(nxt.first);
        vis[nxt.first] = false;
        S.insert(nxt.first);
    }
}

int solution(int N, vector<vector<int> > road, int K) {

    k = K;
    for (int i = 0; i < road.size(); ++i)
    {
        adj[road[i][0]].push_back({ road[i][1], road[i][2] });
        adj[road[i][1]].push_back({ road[i][0], road[i][2] });
    }

    dist[1] = 0;
    vis[1] = true;
    dfs(1);
    S.insert(1);
    
    for(int i : S)
        cout << i << endl;
    

    return S.size();
}
