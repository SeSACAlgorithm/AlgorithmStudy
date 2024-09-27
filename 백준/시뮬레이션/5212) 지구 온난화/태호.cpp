#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int n, m;
int minx = 9999, miny = 9999, maxx = -1, maxy = -1;

char board[11][11];
char sub[11][11];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            sub[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 'X')
            {
                int cnt = 0;

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = dx[dir] + i;
                    int ny = dy[dir] + j;
                
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) 
                        ++cnt;
                    else if (board[nx][ny] == '.')
                        ++cnt;

                    
                }

                if (cnt > 2)
                {
                    sub[i][j] = '.';
                }
                else
                {
                    minx = min(i, minx);
                    miny = min(j, miny);
                    maxx = max(i, maxx);
                    maxy = max(j, maxy);
                }
            }
        }
    }





    for (int i = minx; i <= maxx; i++) 
    {
        for (int j = miny; j <= maxy; j++) 
        {
            cout << sub[i][j];
        }

        cout << '\n';
    }

    return 0;
}
