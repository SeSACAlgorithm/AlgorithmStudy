#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int v, e, place;
vector<pair<int, int>> adj[1002];


int Dijkstra(int st, int en)
{
    vector<int> d(v + 2, 0x3f3f3f3f);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    d[st] = 0;
    pq.push({d[st], st});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top(); pq.pop();

        if(d[cur.second] != cur.first) continue;

        for (auto nxt : adj[cur.second])
        {
            int sum = d[cur.second] + nxt.first;

            if (d[nxt.second] > sum)
            {
                d[nxt.second] = sum;
                pq.push({ sum, nxt.second});
            }
        }
    }

    return d[en];
}


int main()
{
    cin >> v >> e >> place;

    for (int i = 0; i < e; ++i)
    {
        int a, b, dist; cin >> a >> b >> dist;
        adj[a].push_back({dist, b});
    }

    int answer = 0;

    for (int i = 1; i <= v; ++i)
        answer = max(answer, Dijkstra(i, place) + Dijkstra(place, i));
        
    cout << answer;

}
