#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int node1, node2;
    vector<vector<int>> network(N + 1);
    int limit = N - 1;
    // 연결 정보 저장
    // 입력 시점에서 부모-자식을 구분할 수 없으므로 양방향으로 저장
    for (int i = 0; i < limit; ++i)
    {
        cin >> node1 >> node2;
        network[node1].push_back(node2);
        network[node2].push_back(node1);
    }

    // BFS를 위한 큐와 방문 정보를 저장할 vector 선언
    vector<int> parents(N - 1);
    queue<int> que;
    que.push(1);
    vector<bool> visited(N + 1);
    visited[1] = true;
    // BFS 탐색
    while(false == que.empty())
    {
        int cur = que.front();
        que.pop();
        // 연결된 노드가 없다면 스킵 
        if (network[cur].empty())
            continue;

        for(const int& child : network[cur])
        {
            // 이미 방문한 노드(부모)라면 스킵
            if (visited[child])
                continue;

            parents[child - 2] = cur;
            visited[child] = true;
            que.push(child);
        }
    }

    for (const int& p : parents)
        cout << p << "\n";
}