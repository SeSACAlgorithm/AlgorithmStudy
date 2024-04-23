#include <string>
#include <vector>

using namespace std;

vector<int> adj[102];

void dfs(vector<int>* adj, int cur, vector<bool>& vis, int& cnt)
{
    vis[cur] = true;
    ++cnt;

    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;
        dfs(adj, nxt, vis, cnt);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n + 1;


    for (int i = 0; i < wires.size(); ++i)
    {

        vector<bool> vis(wires.size() + 2);

        for(int j = 0; j < wires.size(); ++j)
        {
            if(i == j) continue;

            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }

        int k = 0;
        dfs(adj, 1, vis, k);
        int x = n - k;

        x = abs(x - k);

        for(int j = 0; j < 101; ++j)
            adj[j].clear();

        answer = min(answer, x);
    }

    return answer;
}
