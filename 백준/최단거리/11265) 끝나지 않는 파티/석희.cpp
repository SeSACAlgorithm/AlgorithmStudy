#define MAX 500

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int graph[MAX+1][MAX+1];

void Input()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void PloydWarshall()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void Solve()
{
    int A, B, C;
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        if(graph[A][B] <= C) cout << "Enjoy other party" << "\n";
        else cout << "Stay here" << "\n";
    }
}

int main(void)
{
    Input();
    PloydWarshall();
    Solve();
}