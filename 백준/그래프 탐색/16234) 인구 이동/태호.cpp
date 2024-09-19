#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, mn, mx, result = 0;
int board[51][51];
int dist[51][51];
int average[51][51];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int CrossLine(pair<int, int> start, int line)
{
    queue<pair<int, int>> que;
    que.push(start);

    int total = board[start.first][start.second];
    int cnt = 1;

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny]) continue;

            int num = abs(board[nx][ny] - board[cur.first][cur.second]);
            if (num < mn || num > mx) 
                continue;

            ++cnt;
            total += board[nx][ny];
            dist[nx][ny] = line;
            que.push({ nx, ny });
        }
    }

    average[start.first][start.second] = total / cnt;

    return total;
}

void Search(pair<int, int> start)
{
    queue<pair<int, int>> que;
    que.push(start);

    int aver = average[start.first][start.second];
    int curDist = dist[start.first][start.second];

    dist[start.first][start.second] = -1;
    
    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny] != curDist) continue;

            board[nx][ny] = aver;
            dist[nx][ny] = -1;
            que.push({ nx, ny });
        }
    }

    board[start.first][start.second] = aver;
}

void Solve()
{
    while (true)
    {
        int line = 1;
        bool cond = false;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j]) continue;

                dist[i][j] = line;

                if (board[i][j] == CrossLine({i, j}, line))
                    dist[i][j] = false;
                else
                {
                    ++line;
                    cond = true;
                }
                    
            }
        }
        
        if (!cond)
            break;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!dist[i][j] || dist[i][j] == -1) continue;

                Search({i, j});
            }
        }

        ++result;

        for(int i = 0; i < n; ++i)
            fill(dist[i], dist[i] + n, 0);
    }

    cout << result;

}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mn >> mx;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    
    Solve();

    return 0;
}
