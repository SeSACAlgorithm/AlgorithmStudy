#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nodes, edges;
    cin >> nodes >> edges;

    int start;
    cin >> start;

    map<int, map<int, int>> distance;
    int node_a, node_b, dist;
    for(int i = 0; i < edges; ++i)
    {
        cin >> node_a >> node_b >> dist;

        // 거리 값이 없거나 더 먼 거리로 저장되어 있다면 현재 거리로 갱신
        if(distance[node_a].count(node_b) == 0 || distance[node_a][node_b] > dist) 
            distance[node_a][node_b] = dist;
    }

    vector<int> node(nodes + 1, numeric_limits<int>::max());
    node[start] = 0;
    vector<bool> visited(nodes + 1, false);
    visited[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, start);

    while(false == que.empty())
    {
        int cur_cost = que.top().first;
        int cur_node = que.top().second;
        que.pop();
        // 이미 더 짧은 거리로 갱신했다면 스킵
        if (cur_cost > node[cur_node]) continue;

        for(auto it = distance[cur_node].begin(); it != distance[cur_node].end(); ++it)
        {
            if (visited[it->first]) continue;

            if (node[it->first] > cur_cost + it->second)
            {
                node[it->first] = cur_cost + it->second;
                que.emplace(node[it->first], it->first);
            }
        }
        visited[cur_node] = true;
    }

    for (int i = 1; i < node.size(); ++i)
    {
        if (node[i] == numeric_limits<int>::max()) 
            cout << "INF" << "\n";
        else              
            cout << node[i] << "\n";
    }
}
