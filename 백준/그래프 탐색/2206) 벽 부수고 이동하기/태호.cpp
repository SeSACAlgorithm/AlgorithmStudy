#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

char board[1001][1001];
int dist[1001][1001][2];

int n, m;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

const int INF = 0x7f7f7f7f;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];

    queue<tuple<int, int, bool>> Q;
    Q.push({0, 0, 0});

    dist[0][0][0] = 1;

    while (!Q.empty())
    {
        int x, y;
        bool d;
        tie(x, y, d) = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;

            if (board[nx][ny] == '1' && !d)
            {
                if (dist[nx][ny][1] == 0)
                {
                    dist[nx][ny][1] = dist[x][y][0] + 1;
                    Q.push({ nx, ny, true });
                }
            }

            else if (board[nx][ny] == '0')
            {
                if (dist[nx][ny][d] == 0)
                {
                    dist[nx][ny][d] = dist[x][y][d] + 1;
                    Q.push({ nx, ny, d });
                }
            }
        }
        
    }

    int ans = min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    if (ans == 0) ans = max(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
    if (ans == 0) ans = -1;

    cout << ans << "\n";
}
