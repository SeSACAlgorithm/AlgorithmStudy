#define MAX_N 100000
#define MAX_M 500000
#define INF 100000000

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int friends[3];

int M;
vector<pair<int, int>> vRoad[MAX_N + 1];        // 노드, 비용

int dist[3][MAX_N+1];

void Init()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 1; j <= N; j++)
            dist[i][j] = INF;
    }
}

void Dijkstra(int friendNum, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     // 비용, 노드

    dist[friendNum][start] = 0;
    pq.push({0, start});

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(cost > dist[friendNum][node]) continue;

        for(int i = 0; i < vRoad[node].size(); i++)
        {
            int nextNode = vRoad[node][i].first;
            int nextCost = vRoad[node][i].second;

            if(nextCost + cost < dist[friendNum][nextNode])
            {
                dist[friendNum][nextNode] = nextCost + cost;
                pq.push({nextCost + cost ,nextNode});
            }
        }
    }
}

void Input()
{
    cin >> N;
    for(int i = 0; i < 3; i++) cin >> friends[i];

    cin >> M;
    int D, E, L;
    for(int i = 0; i < M; i++)
    {
        cin >> D >> E >> L;
        vRoad[D].push_back({E, L});
        vRoad[E].push_back({D, L});
    }
}

void FindAnswer()
{
    int answer = 0;
    int maxDist = 0;

    for(int i = 1; i <= N; i++)
    {
        if(friends[0] == i || friends[1] == i || friends[2] == 1) continue;

        int minDist = min(dist[0][i], min(dist[1][i], dist[2][i]));
        if(maxDist < minDist)
        {
            maxDist = minDist;
            answer = i;
        }
    }

    cout << answer;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;

    Input();
    Init();

    for(int i = 0; i < 3; i++)
    {
        Dijkstra(i, friends[i]);
    }
    FindAnswer();
}