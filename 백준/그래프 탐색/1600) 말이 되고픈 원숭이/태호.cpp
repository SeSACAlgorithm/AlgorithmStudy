#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int k, h, w;

int board[203][203];
int dist[32][203][203];
bool visit[200002];

int defaultX[4] = {1, -1, 0, 0};
int defaultY[4] = {0, 0, -1, 1};

int knightX[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int knightY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int MX = 0;

struct coord
{
    int x, y, num;
};

queue<coord> que;

int main(void) {

    ios::sync_with_stdio(0); cin.tie(0);
        
    cin >> k >> w >> h;

    if (w == 1 && h == 1)
    {
        cout << 0;
        return 0;
    }

    MX = h * w * 2;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int x = 0; x <= k; ++x)
        for(int i = 0; i < h; ++i)
            fill(dist[x][i], dist[x][i] + w + 1, MX);

    que.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 8; ++dir)
        {
            int nx = knightX[dir] + cur.x;
            int ny = knightY[dir] + cur.y;

            if (nx < 0 || ny < 0 || nx >= h || ny >= w || cur.num >= k) continue;
            if (board[nx][ny] || dist[cur.num + 1][nx][ny] <= dist[cur.num][cur.x][cur.y] + 1) continue;
            dist[cur.num + 1][nx][ny] = dist[cur.num][cur.x][cur.y] + 1;
            que.push({ nx, ny, cur.num + 1 });
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = defaultX[dir] + cur.x;
            int ny = defaultY[dir] + cur.y;

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(board[nx][ny] || dist[cur.num][nx][ny] <= dist[cur.num][cur.x][cur.y] + 1) continue;
            dist[cur.num][nx][ny] = dist[cur.num][cur.x][cur.y] + 1;
            que.push({nx, ny, cur.num});
        }  
    }

    int result = h * w * 2;

    for(int i = 0; i <= k; ++i)
        if(dist[i][h - 1][w - 1] != MX)
            result = min(result, dist[i][h - 1][w - 1]);

    result == h * w * 2 ? cout << -1 : cout << result;

    return 0;
}
