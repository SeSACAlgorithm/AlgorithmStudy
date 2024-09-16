#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int board1[5][5][5];
int board2[5][5][5];
int board3[5][5][5];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

const int MX = 0x7f7f7f7f; 
int result = 0x7f7f7f7f;

int bfs()
{
    queue<tuple<int, int, int>> que;
    int visit[5][5][5] = {0};    

    if (board2[0][0][0] && board2[4][4][4])
    {
        que.push({ 0, 0, 0 });
        visit[0][0][0] = 1;
    }

    while (!que.empty())
    {
        auto[x, y, z] = que.front();
        que.pop();

        for (int dir = 0; dir < 6; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            int nz = dz[dir] + z;

            if(nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
            if(visit[nz][ny][nx] || !board2[nz][ny][nx]) continue;
            if (nz == 4 && ny == 4 && nx == 4)
            {
                return visit[z][y][x];
            }
            visit[nz][ny][nx] = visit[z][y][x] + 1;
            que.push({nx, ny, nz});

        }
    }

    return MX;
}


void Rotate(int mazeNum, int dir)
{
    // 90
    if (dir == 1)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                board2[mazeNum][i][j] = board1[mazeNum][4 - j][i];
            }
        }

    }
    // 180
    else if (dir == 2)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                board2[mazeNum][i][j] = board1[mazeNum][4 - i][4 - j];
            }
        }
    }
    // 270
    else if (dir == 3)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                board2[mazeNum][i][j] = board1[mazeNum][j][4 - i];
            }
        }
    }
}

void Solve()
{
    vector<int> permutation(5);

    for(int i = 0; i < 5; ++i)
        permutation[i] = i;

    do
    {
        for (int k = 0; k < 5; ++k)
            for (int i = 0; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    board1[k][i][j] = board3[permutation[k]][i][j];

        for (int tmp = 0; tmp < 1024; ++tmp)
        {
            for (int k = 0; k < 5; ++k)
                for (int i = 0; i < 5; ++i)
                    for (int j = 0; j < 5; ++j)
                        board2[k][i][j] = board1[k][i][j];

            int brute = tmp;

            for (int i = 0; i < 5; ++i)
            {
                int dir = brute % 4;
                brute /= 4;
                Rotate(i, dir);
            }

            result = min(result, bfs());
        }

    } while(next_permutation(permutation.begin(), permutation.end()));
    
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    for (int k = 0; k < 5; ++k)
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> board3[k][i][j];

    Solve();

    result == MX ? cout << -1 : cout << result;
}
