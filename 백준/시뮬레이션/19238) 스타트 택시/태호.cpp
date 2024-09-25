#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, f, result = 0;
int board[22][22];
int dist[22][22];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

pair<int, int> taxiPos;
pair<int, int> dest;
vector<pair<int, int>> startPos;
unordered_map<int, pair<int, int>> endPos;

void Input()
{
    cin >> n >> m >> f;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
   

    int x, y; cin >> x >> y;
    taxiPos = { x - 1, y - 1 };

    int num = 1;

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        
        board[x1][y1] = ++num;
        startPos.push_back({ x1, y1 });
        endPos.insert({ num, { x2, y2 }});
    }
}

bool MoveSource()
{
    if (board[taxiPos.first][taxiPos.second] > 1)
    {
        dest = endPos[board[taxiPos.first][taxiPos.second]];
        endPos.erase(board[taxiPos.first][taxiPos.second]);
        board[taxiPos.first][taxiPos.second] = 0;
        return true;
    }

    queue<tuple<int, int, int>> que;

    que.push({ taxiPos.first, taxiPos.second, 0 });

    for(int i = 0; i < 22; ++i)
        fill(dist[i], dist[i] + 22, 0);

    int minDist = 0x7f7f7f7f;

    while (!que.empty())
    {
        auto[x, y, d] = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == 1 || dist[nx][ny] || f - d - 1 < 0) continue;

            if (board[nx][ny] > 1)
            {
                // 최단거리라면 바로 넣자
                if (minDist > d)
                {
                    minDist = d;
                    dest = endPos[board[nx][ny]];
                    taxiPos = {nx, ny};
                }
                // 거리가 같다면
                else if (minDist == d)
                {
                    // 행이 작다면 넣어주자
                    if(taxiPos.first > nx)
                    {
                        taxiPos = { nx, ny };
                        dest = endPos[board[nx][ny]];
                    }
                    // 행도 같다면
                    else if(taxiPos.first == nx)
                    {
                        // 열이 작은곳에 넣어주자.
                        if (taxiPos.second > ny)
                        {
                            taxiPos = { nx, ny };
                            dest = endPos[board[nx][ny]];
                        }
                        
                    }

                }
            }


            dist[nx][ny] = d + 1;
            que.push({nx, ny, d + 1});
        }
    }

    if (board[taxiPos.first][taxiPos.second] > 1)
    {
        endPos.erase(board[taxiPos.first][taxiPos.second]);
        board[taxiPos.first][taxiPos.second] = 0;
        f -= minDist + 1;
        return true;
    }

    return false;
}


bool MoveDest()
{

    queue<tuple<int, int, int>> que;

    que.push({ taxiPos.first, taxiPos.second, 0 });

    for (int i = 0; i < 22; ++i)
        fill(dist[i], dist[i] + 22, 0);


    while (!que.empty())
    {
        auto [x, y, d] = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 1 || dist[nx][ny] || f - d - 1 < 0) continue;

            if (nx == dest.first && ny == dest.second)
            {
                taxiPos = {nx, ny};
                f += d + 1;
                return true;
            }

            dist[nx][ny] = d + 1;
            que.push({ nx, ny, d + 1 });
        }
    }

    return false;
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Input();

    for (int i = 0; i < m; ++i)
    {
        if (!MoveSource() || !MoveDest())
        {
            f = -1;
            break;
        }

        
    }

    cout << f;


    return 0;
}
