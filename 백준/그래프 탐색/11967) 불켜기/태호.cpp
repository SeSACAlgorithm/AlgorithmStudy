#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<pair<int, int>> board[102][102];

bool visit[102][102];
bool bright[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> que;

void InsertBright(int x, int y)
{
    for (auto [nextX, nextY] : board[x][y]) {
        bright[nextX][nextY] = true;  
    }
}

void SearchDest(int x, int y)
{
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = dx[dir] + x;
        int ny = dy[dir] + y;

        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (!visit[nx][ny] && bright[nx][ny])
        {
            que.push({ nx, ny });
            visit[nx][ny] = true;
        }
    }
}

void ResearchDest()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!visit[i][j]) continue;

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = dx[dir] + i;
                int ny = dy[dir] + j;

                if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                if (!bright[nx][ny] || visit[nx][ny]) continue;

                que.push({ nx, ny });
                visit[nx][ny] = true;
            }
        }
    }
}


int main(void) {

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        board[x1][y1].push_back({x2, y2});
    }
    
    bright[1][1] = true;  
    que.push({ 1, 1 });
    visit[1][1] = true;

    InsertBright(1, 1);


    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();
        InsertBright(x, y);
        SearchDest(x, y);
        ResearchDest();
    }

    int result = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if(bright[i][j])
                ++result;

    cout << result;

    return 0;
}
