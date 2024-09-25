#include <bits/stdc++.h>

using namespace std;

int n, q, sum = 0, cnt = 0;
int board[70][70];
int rotated[70][70];
bool visited[70][70];

void Rotate(int x, int y, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            rotated[x + j][y + size - 1 - i] = board[x + i][y + j];
        }
    }
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    int pw = (1 << n);

    for (int i = 0; i < pw; ++i)
    {
        for (int j = 0; j < pw; ++j)
        {
            cin >> board[i][j];
        }
    }

    int l;
    for (int k = 0; k < q; ++k)
    {
        cin >> l;

        int num = (1 << l); 

        for (int i = 0; i < pw; i += num)
            for (int j = 0; j < pw; j += num)
                Rotate(i, j, num);


        vector<pair<int, int>> icelink;

        for (int i = 0; i < pw; ++i)
        {
            for (int j = 0; j < pw; ++j)
            {
                if(rotated[i][j] == 0) continue;

                int cnt = 0;

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = dx[dir] + i;
                    int ny = dy[dir] + j;

                    if(nx < 0 || ny < 0 || nx >= pw || ny >= pw) continue;
                    
                    if(rotated[nx][ny])
                        ++cnt;
                }


                if(cnt < 3)
                    icelink.push_back({i, j});
            }
        }

        for(auto cur : icelink)
            --rotated[cur.first][cur.second];
  
        memcpy(board, rotated, sizeof(int) * 70 * 70);
    }


    queue<pair<int, int>> que;
    

    for (int i = 0; i < pw; ++i)
    {
        for (int j = 0; j < pw; ++j)
        {
            sum += board[i][j];

            if (board[i][j] && !visited[i][j])
            {
                int mx = 1;

                que.push({i, j});
                visited[i][j] = true;


                while (!que.empty())
                {
                    auto cur = que.front();
                    que.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = dx[dir] + cur.first;
                        int ny = dy[dir] + cur.second;

                        if (nx < 0 || ny < 0 || nx >= pw || ny >= pw) continue;

                        if (board[nx][ny] && !visited[nx][ny])
                        {
                            visited[nx][ny] = true;
                            que.push({nx, ny});
                            ++mx;
                        }
                            
                    }
                }

                cnt = max(mx, cnt);
            }
                

        }
    }

    cout << sum << '\n' << cnt;

    return 0;
}
