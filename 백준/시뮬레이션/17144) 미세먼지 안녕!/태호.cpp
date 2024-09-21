#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, t, result = 0;
pair<int, int> air[2];
int board[51][51];
int arr[51][51];

/*

0 30 7
x 10 0
x 0 20

7 / 5 = 1
7 - 2 = 5

20 / 5 = 4
20 - 8 = 12
...

6 15 11
0 10 7
0 4 12
*/

void Input()
{
    cin >> r >> c >> t;

    int OneMinus = 0;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == -1)
            {
                air[OneMinus++] = { i, j };
            }

        }
    }
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Diffusion()
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] == -1 || board[i][j] == 0) continue;

            int diff = board[i][j] / 5;
            int size = 0;

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = dx[dir] + i;
                int ny = dy[dir] + j;

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (board[nx][ny] == -1) continue;
                arr[nx][ny] += diff;
                ++size;
            }

            board[i][j] -= diff * size;
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] == -1) continue;
            board[i][j] += arr[i][j];
            arr[i][j] = 0;
        }
    }
}

void AirFirst(int x, int y)
{
    // 오른쪽
    int pre = board[x][y + 1];
    board[x][y + 1] = 0;

    for (int i = y + 2; i < c; ++i)
    {
        int tmp = board[x][i];
        board[x][i] = pre;
        pre = tmp;
    }

    // 위쪽
    for (int i = x - 1; i >= 0; --i)
    {
        int tmp = board[i][c - 1];
        board[i][c - 1] = pre;
        pre = tmp;
    }

    // 왼쪽
    for (int i = c - 2; i >= 0; --i)
    {
        int tmp = board[0][i];
        board[0][i] = pre;
        pre = tmp;
    }

    // 아래쪽
    for (int i = 1; i < x; ++i)
    {
        int tmp = board[i][0];
        board[i][0] = pre;
        pre = tmp;
    }

}

void AirSecond(int x, int y)
{
    // 오른쪽
    int pre = board[x][y + 1];
    board[x][y + 1] = 0;

    for (int i = y + 2; i < c; ++i)
    {
        int tmp = board[x][i];
        board[x][i] = pre;
        pre = tmp;
    }

    // 아래쪽
    for (int i = x + 1; i < r; ++i)
    {
        int tmp = board[i][c - 1];
        board[i][c - 1] = pre;
        pre = tmp;
    }

    // 왼쪽
    for (int i = c - 2; i >= 0; --i)
    {
        int tmp = board[r - 1][i];
        board[r - 1][i] = pre;
        pre = tmp;
    }

    // 위쪽
    for (int i = r - 2; i > x; --i)
    {
        int tmp = board[i][0];
        board[i][0] = pre;
        pre = tmp;
    }

}

void AirRobot()
{
    AirFirst(air[0].first, air[0].second);
    AirSecond(air[1].first, air[1].second);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    Input();

    while (t--)
    {
        Diffusion();
        AirRobot();
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if(board[i][j] == -1) continue;
            result += board[i][j];
        }
    }

    cout << result;


    return 0;
}
