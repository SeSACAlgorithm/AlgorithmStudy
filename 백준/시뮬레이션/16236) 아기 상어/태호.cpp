#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int n, seconds = 0;
int board[21][21];
int dist[21][21];
pair<int, int> babySharkPos;
int babySharkSize = 2, babySharkExp = 0;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;


// 크기가  같은 물고기는 길만 지나갈 수 있음
//     ""  작은 물고기는 먹음
//     ""  큰   물고기는 못지나감, 못먹음

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool bfs()
{
    queue<tuple<int, int, int>> que;

    que.push({0, babySharkPos.first, babySharkPos.second});
    dist[babySharkPos.first][babySharkPos.second] = 1;

    while (!que.empty())
    {
        auto[curDist, x, y] = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] > babySharkSize || dist[nx][ny]) continue;
            if (!pq.empty())
            {
                auto [pqDist, pqX, pqY] = pq.top();

                if(pqDist < curDist)
                    continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            
            if (board[nx][ny] && board[nx][ny] != babySharkSize)
                pq.push({ dist[nx][ny], nx, ny });
              

            que.push({dist[nx][ny], nx, ny});
        }
    }


    if (pq.empty())
        return false;

    auto[dist, x, y] = pq.top();
    
    board[babySharkPos.first][babySharkPos.second] = 0;
    board[x][y] = 9;
    babySharkPos = {x, y};

    seconds += dist - 1;

    ++babySharkExp;

    if (babySharkSize == babySharkExp)
    {
        ++babySharkSize;
        babySharkExp = 0;
    }

    return true;
}

void Solve()
{
    while (true)
    {
        if (!bfs())
            break;

        while(!pq.empty())
            pq.pop();

        for (int i = 0; i < n; ++i)
            fill(dist[i], dist[i] + n, 0);
    }

    cout << seconds;

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 9)
                babySharkPos = {i, j};
        }
    }

    Solve();


    return 0;
}
