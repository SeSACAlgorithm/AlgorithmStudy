#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, result = 0;
int board[2002][2002];
bool air[4][2002][2002];
queue<tuple<int, int, int>> que;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Solve()
{

    while (!que.empty())
    {
        auto[d, x, y] = que.front();
        que.pop();

        int nx = dx[d] + x;
        int ny = dy[d] + y;
        int dir = d;

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(air[d][nx][ny]) continue;
        air[dir][nx][ny] = true;

        if(board[nx][ny] == 1 && dir % 2 == 1) continue;
        if(board[nx][ny] == 2 && dir % 2 == 0) continue;
        if(board[nx][ny] == 3)
        {
            if(dir == 0)        dir = 3;
            else if (dir == 1)  dir = 2;
            else if (dir == 2)  dir = 1;
            else if (dir == 3)  dir = 0;
        }
        if (board[nx][ny] == 4)
        {
            if (dir == 0)       dir = 1;
            else if (dir == 1)  dir = 0;
            else if (dir == 2)  dir = 3;
            else if (dir == 3)  dir = 2;
        }

        que.push({dir, nx, ny});
    }

}

void Input()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 9)
            {
                for (int dir = 0; dir < 4; ++dir)
                {
                    air[dir][i][j] = true;
                    que.push({ dir, i, j });
                }
            }
        }
    }

}

void Answer()
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (air[k][i][j])
                {
                    ++result;
                    break;
                }
                    
            }
        }
    }

    cout << result;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Input();
    Solve();
    Answer();


    return 0;
}
