#define INF (int)1e9

#include <iostream>
#include <algorithm>

using namespace std;

int V, E;
int graph[401][401];

void Input()
{
    cin >> V >> E;

    for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            if(i != j)  graph[i][j] = INF;
        }
    }

    int a, b, c;
    for(int i = 0 ; i < E; i++)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
}

void Floyd()
{
    for(int k = 1; k <= V; k++)
    {
        for(int i = 1; i <= V; i++)
        {
            for(int j = 1; j <= V; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

void Solve()
{
    int answer = INF;
    for(int i = 1; i <= V; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            if (i == j) continue;
            answer = min(answer, graph[i][j]+graph[j][i]);
        }
    }

    if(answer == INF) cout << "-1";
    else cout << answer;
}

int main(void)
{
    Input();
    Floyd();
    Solve();
}