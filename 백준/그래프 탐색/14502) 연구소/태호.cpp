#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

int board[10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> que;
queue<pair<int, int>> virus;

int result = 0;

void bfs()
{
    bool visit[10][10] = { false };


    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] || visit[nx][ny]) continue;
            visit[nx][ny] = true;
            que.push({nx, ny});
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!visit[i][j] && board[i][j] == 0)
                ++cnt;

    result = max(result, cnt);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pair<int, int>> emptyPlace;
    

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                emptyPlace.push_back({ i, j });
            }
            else if (board[i][j] == 2)
            {
                virus.push({i, j});
            }
        }
    }

    vector<int> permutation(emptyPlace.size(), 0);
    fill(permutation.begin(), permutation.begin() + 3, 1);

    do
    {
        vector<pair<int, int>> vec;
        
        for (int i = 0; i < permutation.size(); ++i)
        {
            if (permutation[i])
                vec.push_back({ emptyPlace[i].first, emptyPlace[i].second });
        }

        que = virus;

        for (int i = 0; i < vec.size(); ++i)
            board[vec[i].first][vec[i].second] = 1;

        bfs();

        for (int i = 0; i < vec.size(); ++i)
            board[vec[i].first][vec[i].second] = 0;


    } while(prev_permutation(permutation.begin(), permutation.end()));

    cout << result;
}
