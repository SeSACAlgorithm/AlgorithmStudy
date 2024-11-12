#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int map[15][15];

void Input()
{
    memset(map, 0, sizeof(map));
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

int FindBugs(int sx, int sy)
{
    int sum = 0;
    for(int i = sx; i < sx + M; i++)
    {
        for(int j = sy; j < sy + M; j++)
        {
            sum += map[i][j];
        }
    }
    return sum;
}

void Solve()
{
    int answer = 0;

    for(int i = 0; i <= N - M; i++)
    {
        for(int j = 0; j <= N - M; j++)
        {
            answer = max(answer, FindBugs(i, j));
        }
    }

    cout << answer << "\n";
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