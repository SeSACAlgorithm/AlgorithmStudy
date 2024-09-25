#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, result = 0;
int board[500][500];

int kx[4][10] = 
{
    {1, -1, 1, -1, 1, -1, 2, -2, 0, 0},
    {-1, -1, 0, 0, 1, 1, 0, 0, 2, 1},
    {1, -1, 1, -1, 1, -1, 2, -2, 0, 0},
    {1, 1, 0, 0, -1, -1, 0, 0, -2, -1}
};

int ky[4][10] = 
{
    {1, 1, 0, 0, -1, -1, 0, 0, -2, -1},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {-1, -1, 0, 0, 1, 1, 0, 0, 2, 1},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
};

int sc[9] = {1, 1, 7, 7, 10, 10, 2, 2, 5};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void Move(int x, int y, int dir)
{
    if(!board[x][y])
        return;

    int sand = board[x][y];
    int total = 0;

    for (int i = 0; i < 9; ++i)
    {
        int nx = kx[dir][i] + x;
        int ny = ky[dir][i] + y;

        int num = sand * sc[i] / 100;
        total += num;

        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            result += num;
        else
            board[nx][ny] += num;
    }

    int nx = kx[dir][9] + x;
    int ny = ky[dir][9] + y;

    int remaining = sand - total;

    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        result += remaining;
    else
        board[nx][ny] += remaining;


    board[x][y] = 0;
}

void Solve()
{
    int dir = 0;
    int moveNum = 1;

    int x = n / 2;
    int y = x;

    while (true)
    {

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < moveNum; ++j)
            {
                x += dx[dir];
                y += dy[dir];

                Move(x, y, dir);

                if (x == 0 && y == 0)
                    return;
            }

            dir = (dir + 1) % 4;
        }

        ++moveNum;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> board[i][j];

    Solve();
    cout << result;

    return 0;
}
