#define MAX 100

#include <iostream>

using namespace std;

int N;

int graph[MAX + 1][MAX + 1];

void Input()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void FloydWarshall()
{
    // 중간 노드
    for(int k = 0; k < N; k++)
    {
        // 시작 노드
        for(int i = 0; i < N; i++)
        {
            // 도착 노드
            for(int j = 0; j < N; j++)
            {
                if(graph[i][k] && graph[k][j]) graph[i][j] = 1;
            }
        }
    }
}

void Output()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    Input();
    FloydWarshall();
    Output();
}