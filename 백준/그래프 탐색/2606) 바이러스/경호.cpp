#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 연결 정보 저장
    vector<vector<int>> network(N + 1);
    int pc1, pc2;
    for(int i = 0; i < M; ++i)
    {
        cin >> pc1 >> pc2;
        network[pc1].push_back(pc2);
        network[pc2].push_back(pc1);
    }
    // BFS를 위한 큐와 방문 여부를 저장할 vector 선언
    vector<bool> visited(N + 1, false);
    visited[1] = true;
    queue<int> que;
    que.push(1);

    int answer = 0;
    while(false == que.empty())
    {
        int cur = que.front();
    	que.pop();
        ++answer;
        // 연결된 pc가 없다면 스킵
        if (network[cur].empty())
            continue;

        for(const int& next : network[cur])
        {
            // 이미 방문한 pc라면 스킵
            if (visited[next]) 
                continue;

            que.push(next);
            visited[next] = true;
        }
    }
    // 1번 pc를 제외하고 출력
    cout << answer - 1;
}