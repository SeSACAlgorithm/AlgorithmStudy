#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void Solve()
{
    int answer = 0;
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            sum = map[i][j];
            for(int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                sum += map[nx][ny];
            }
            answer = max(sum, answer);
            sum = 0;
        }
    }

    cout << answer << "\n";
}


void Input()
{
    memset(map, 0 , sizeof(map));

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

int main(void)
{
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++)
    {
        cout << "#" << test_case << " ";
        Input();
        Solve();
    }
}