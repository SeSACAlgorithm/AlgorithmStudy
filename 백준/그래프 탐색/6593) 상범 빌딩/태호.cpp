#include <bits/stdc++.h>

using namespace std;

char board[32][32][32];
int dist[32][32][32];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> vec;

    while (true)
    {

        int x, y, z; cin >> z >> x >> y;

        if (x == 0 && y == 0 && z == 0)
            break;
            

        queue<tuple<int, int, int>> Q;
        int endX = 0, endY = 0, endZ = 0;


        for (int h = 0; h < z; ++h)
        {
            for (int n = 0; n < x; ++n)
            {
                for (int m = 0; m < y; ++m)
                {
                    cin >> board[n][m][h];

                    if (board[n][m][h] == 'S')
                    {
                        dist[n][m][h] = 0;
                        Q.push({ n, m, h });
                    }
                    else if (board[n][m][h] == 'E')
                    {
                        endX = n;
                        endY = m;
                        endZ = h;
                        dist[n][m][h] = -1;
                    }
                    else if(board[n][m][h] == '#')
                        dist[n][m][h] = 0;
                    else
                        dist[n][m][h] = -1;
                }
            }
        }

        while (!Q.empty() && dist[endX][endY][endZ] == -1)
        {
            auto cur = Q.front(); Q.pop();
            int CurX, CurY, CurZ;
            tie(CurX, CurY, CurZ) = cur;


            for (int dir = 0; dir < 6; ++dir)
            {
                int nx = dx[dir] + CurX;
                int ny = dy[dir] + CurY;
                int nz = dz[dir] + CurZ;

                if(nx < 0 || nx >= x || ny < 0 || ny >= y || nz < 0 || nz >= z) continue;
                if(board[nx][ny][nz] == '#' || dist[nx][ny][nz] >= 0) continue;
                dist[nx][ny][nz] = dist[CurX][CurY][CurZ] + 1;
                Q.push({nx, ny, nz});
            }
        }
        //Escaped in 11 minute(s).
        //Escaped in 11 minute(s).
        if (dist[endX][endY][endZ] != -1)
        {
            string str = "Escaped in " + to_string(dist[endX][endY][endZ]) + " minute(s).";
            vec.push_back(str);
        }
        else
            vec.push_back("Trapped!");

    }


    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << '\n';
   


    return 0;
}
