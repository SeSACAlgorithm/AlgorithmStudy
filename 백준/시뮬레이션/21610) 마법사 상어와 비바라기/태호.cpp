#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define Y groom[index].second
#define X groom[index].first

using namespace std;

int n, m, result = 0;
int board[51][51];
bool sub[51][51];

int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };

vector<pair<int, int>> groom;
queue<pair<int, int>> movement;

enum EDirection
{
    None,
    Left,
    LeftUp,
    Up,
    RightUp,
    Right,
    RightDown,
    Down,
    LeftDown
};


void Move(int dir, int index)
{
    if (dir == Left)
    {
        --Y;

        if (Y == -1) Y = n - 1;
    }
    else if (dir == LeftUp)
    {
        --X;
        --Y;

        if (X == -1)    X = n - 1;
        if (Y == -1)    Y = n - 1;
    }
    else if (dir == Up)
    {
        --X;

        if (X == -1) X = n - 1;
    }
    else if (dir == RightUp)
    {
        --X;
        ++Y;

        if (X == -1) X = n - 1;
        if (Y == n) Y = 0;
    }
    else if (dir == Right)
    {
        ++Y;

        if (Y == n) Y = 0;
    }
    else if (dir == RightDown)
    {
        ++X;
        ++Y;

        if (X == n) X = 0;
        if (Y == n) Y = 0;
    }
    else if (dir == Down)
    {
        ++X;

        if (X == n) X = 0;
    }
    else if (dir == LeftDown)
    {
        ++X;
        --Y;

        if (X == n) X = 0;
        if (Y == -1) Y = n - 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int d, s; cin >> d >> s;
        movement.push({d, s % n});
    }

    groom.push_back({ n - 1, 0 });
    groom.push_back({ n - 1, 1 });
    groom.push_back({ n - 2, 0 });
    groom.push_back({ n - 2, 1 });

    while (!movement.empty())
    {
        auto [dir, speed] = movement.front();
        movement.pop();

        for (int i = 0; i < speed; ++i)
            for (int j = 0; j < groom.size(); ++j)
                Move(dir, j);

        for (int i = 0; i < groom.size(); ++i)
            ++board[groom[i].first][groom[i].second];

        for (int i = 0; i < groom.size(); ++i)
        {
            int cnt = 0;
            auto cur = groom[i];

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = dx[dir] + groom[i].first;
                int ny = dy[dir] + groom[i].second;
            
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(!board[nx][ny]) continue;

                ++cnt;
            }

            board[cur.first][cur.second] += cnt;
            sub[cur.first][cur.second] = true;
        }

        groom.clear();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!sub[i][j] && board[i][j] >= 2)
                {
                    board[i][j] -= 2;
                    groom.push_back({ i, j });
                }
  
                sub[i][j] = false;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result += board[i][j];


    cout << result;

    return 0;
}
