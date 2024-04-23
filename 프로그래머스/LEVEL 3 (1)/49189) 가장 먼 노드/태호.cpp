bool vis[20002];
vector<int> adj[20002];

int solution(int n, vector<vector<int>> edge) {
    
    int answer = 0;
    int mx = 0;

    for (int i = 0; i < edge.size(); ++i)
    {
        int u = edge[i][0], v = edge[i][1]; 

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> Q;
    Q.push({1, 0});
    vis[1] = true;

    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();

        bool node = false;

        for (int nxt : adj[cur.first])
        {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            Q.push({ nxt, cur.second + 1 });
            node = true;
        }

        if (!node)
        {
            if (mx < cur.second)
            {
                answer = 1;
                mx = cur.second;
            }
            else if (mx == cur.second)
                ++answer;

        }

    }

    return answer;
}
