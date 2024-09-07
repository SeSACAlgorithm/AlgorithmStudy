#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int board[101][101];
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int result = 0;

queue<pair<int, int>> solveQue;

// board는 0인데 양옆위아래 중 두개가 1이라면 다리를 이은거임

/*
    ex)
    4
    0 0 1 1
    0 0 1 1
    1 0 1 0
*/

void FirstSetting()
{
    cin >> n;

    result = n * n + 2;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
}

void Result()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] > 1) continue;

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = dx[dir] + i;
                int ny = dy[dir] + j;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (board[nx][ny] != 1) continue;
                result = min(result, dist[i][j]);
            }
        }
    }

}

void Solve()
{
    while (!solveQue.empty())
    {
        auto cur = solveQue.front();
        solveQue.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] || dist[nx][ny] <= dist[cur.first][cur.second] + 1) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            solveQue.push({ nx, ny });
        }
    }

    Result();
}

void ResetDist()
{
    for (int i = 0; i < n; ++i)
        fill(dist[i], dist[i] + n, n * n + 1);
}

void BoardSetting()
{
    int current = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!board[i][j] || board[i][j] > 1) continue;
            ++current;
            ResetDist();
            dist[i][j] = 0;

            queue<pair<int, int>> que;
            que.push({ i, j });
            solveQue.push({ i, j });
            board[i][j] = current;

            while (!que.empty())
            {
                auto cur = que.front();
                que.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = dx[dir] + cur.first;
                    int ny = dy[dir] + cur.second;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (board[nx][ny] > 1 || !board[nx][ny]) continue;

                    dist[nx][ny] = 0;
                    board[nx][ny] = current;
                    solveQue.push({nx, ny});
                    que.push({ nx, ny });
                }
            }

            Solve();
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    FirstSetting();
    BoardSetting();

    cout << result;
}
