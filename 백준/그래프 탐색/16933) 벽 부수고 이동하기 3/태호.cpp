#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n, m, k;

struct coord
{
    int x, y, num, dist;
    bool afternoon;
};

int dist[11][1001][1001];
string board[1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int MX = 0x7f7f7f7f;

int main(void) {

    ios::sync_with_stdio(0); cin.tie(0);
        
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        cin >> board[i];
    
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= n; ++j)
            fill(dist[i][j], dist[i][j] + m, MX);

    queue<coord> que;
    que.push({0, 0, 0, 0, true});
    dist[0][0][0] = 0;

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + cur.x;
            int ny = dy[dir] + cur.y;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '1')
            {
                if(cur.num >= k)
                    continue;

                if (!cur.afternoon)
                {
                    que.push({cur.x, cur.y, cur.num, cur.dist + 1, true });
                }
                else
                {
                    if(dist[cur.num + 1][nx][ny] <= cur.dist + 1) continue;

                    que.push({nx, ny, cur.num + 1, cur.dist + 1, false });
                    dist[cur.num + 1][nx][ny] = cur.dist + 1;
                }
            }
            else
            {
                if (dist[cur.num][nx][ny] <= cur.dist + 1) continue;
                que.push({ nx, ny, cur.num, cur.dist + 1, !cur.afternoon });
                dist[cur.num][nx][ny] = cur.dist + 1;
            }
        }
    }

    int result = MX;

    for (int i = 0; i <= k; ++i)
        result = min(result, dist[i][n - 1][m - 1]);

    result == MX ? cout << -1 : cout << result + 1;

    return 0;
}
