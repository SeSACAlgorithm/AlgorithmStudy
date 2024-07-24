#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[302][302];
int ext[302][302];
bool check[302][302];
int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int solve()
{
    int answer = 0;

    while (true)
    {
        int num = 0;

        for (int i = 0; i < n; ++i)
        {
            fill(check[i], check[i] + m, false);
            fill(ext[i], ext[i] + m, 0);
        }
            

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] <= 0 || check[i][j]) continue;

                queue<pair<int, int>> Q;
                Q.push({ i, j });
                check[i][j] = true;
                ++num;

                if (num > 1)
                    return answer;

                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
                        if (board[nx][ny] > 0) continue;
                        --ext[cur.first][cur.second];
                    }

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
                        if(check[nx][ny] || board[nx][ny] <= 0) continue;

                        Q.push({ nx, ny });
                        check[nx][ny] = true;

                    }

                }
            }
        }

        if(!num) return 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                board[i][j] += ext[i][j];

        ++answer;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
  
    cout << solve();

}
