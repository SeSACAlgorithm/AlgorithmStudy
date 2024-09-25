#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int n, m, t, sum = 0;
int board[52][52];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

vector<tuple<int, int, int>> casees;
vector<pair<int, int>> adress;

void Input()
{
    cin >> n >> m >> t;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < t; ++i)
    {
        int x, d, k; cin >> x >> d >> k;
        casees.push_back({x, d, k});
    }

}

void Rotate(int x, int rotCnt)
{
    int sub[52];


    int last = board[x][m - 1];

    for (int i = 0; i < m - 1; ++i)
        sub[(rotCnt + i) % m] = board[x][i];

    sub[rotCnt - 1] = last;

    for(int i = 0; i < m; ++i)
        board[x][i] = sub[i];
}

double Average()
{
    int num = 0, cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] != -1)
            {
                adress.push_back({ i, j });
                ++cnt;
                num += board[i][j];
            }


        }
    }

    return (double)num / (double)cnt;
}

bool Num1()
{
    bool visit[55][55] = { false };
    bool flag = false;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(visit[i][j] || board[i][j] == -1) continue;

            queue<pair<int, int>> que;
            visit[i][j] = true;
            que.push({i, j});

            bool cond = false;

            while (!que.empty())
            {
                auto cur = que.front();
                que.pop();
                
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = dx[dir] + cur.first;
                    int ny = dy[dir] + cur.second;

                    if(ny == -1)
                        ny = m - 1;
                    else if(ny == m)
                        ny = 0;


                    if(nx < 0 || nx >= n) continue;
                    if(visit[nx][ny] || board[nx][ny] == -1 || board[nx][ny] != board[i][j]) continue;
                    visit[nx][ny] = true;
                    board[nx][ny] = -1;
                    cond = true;
                    flag = true;
                    que.push({nx, ny});
                }
            }

            if(cond)
                board[i][j] = -1;

        }
    }

    return flag;
}

void Num2()
{
    double aver = Average();

    for (int j = 0; j < adress.size(); ++j)
    {
        double num = board[adress[j].first][adress[j].second];

        // 같지 않다면
        if (aver + 0.000001 < num || aver - 0.000001 > num)
        {
            // 크다면
            if (num > aver)
            {
                --board[adress[j].first][adress[j].second];
            }
            else
            {
                ++board[adress[j].first][adress[j].second];
            }
        }

    }

    adress.clear();
}



void Solve()
{
    for (int i = 0; i < casees.size(); ++i)
    {
        auto [x, d, k] = casees[i];

        for (int i = 1; i <= n; ++i)
        {
            if (i % x == 0)
            {
                int num = k;

                if (d == 1)
                    num = m - num;

                Rotate(i - 1, num);
            }
        }

        if (!Num1())
        {
            Num2();
        }
    }


   
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Input();
    Solve();

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(board[i][j] != -1)
                sum += board[i][j];

    cout << sum;

    return 0;
}
