#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int result = 0;
string board[12];

bool bfs(int x, int y) 
{

    bool visit[12][6] = { false };

    vector<pair<int, int>> coord;
    queue<pair<int, int>> que;
    que.push({ x, y });
    coord.push_back({ x, y });
    visit[x][y] = true;

    char Puyo = board[x][y];

    while (!que.empty()) 
    {
        auto cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir) 
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if (visit[nx][ny] || board[nx][ny] != Puyo) continue;

            que.push({ nx, ny });
            visit[nx][ny] = true;
            coord.push_back({ nx, ny });
        }
    }

    if (coord.size() < 4)
        return false;

    for (int i = 0; i < coord.size(); ++i) 
    {
        board[coord[i].first][coord[i].second] = '.';
    }

    return true;
}

int main(void) 
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; ++i)
        cin >> board[i];

    bool cond = true;

    while (cond) 
    {

        cond = false;
        
        for (int i = 0; i < 12; ++i) 
        {
            for (int j = 0; j < 6; ++j) 
            {
                if (board[i][j] == '.') continue;

                if (bfs(i, j))
                    cond = true;
            }
        }

        if (cond) 
        {
            ++result;

            for (int j = 0; j < 6; ++j) 
            {
                vector<char> col;

                for (int i = 11; i >= 0; --i) 
                {
                    if (board[i][j] != '.') {
                        col.push_back(board[i][j]);
                    }
                }

                int idx = 11;
                for (char puyo : col) 
                    board[idx--][j] = puyo;
                
                while (idx >= 0) 
                    board[idx--][j] = '.';
            }
        }
    }

    cout << result;
}
