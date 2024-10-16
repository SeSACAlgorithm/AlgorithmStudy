// 문제 분석
/*
    
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[251][251];
int visit[251][251];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int R, C;
int o_all;
int v_all;

void Input()
{
    cin >> R >> C;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
}

void Bfs(int sx, int sy)
{
    int o_count = 0;
    int v_count = 0;

    queue<pair<int, int>> q;

    if(map[sx][sy] == 'o') o_count++;
    else if(map[sx][sy] == 'v') v_count++;

    q.push({sx, sy});
    visit[sx][sy]++;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;        // 맵 밖일 경우
            if(visit[nx][ny] != 0) continue;                            // 이미 확인한 경우
            if(map[nx][ny] == '#') continue;                            // 울타리인 경우

            if(map[nx][ny] == 'o') o_count++;
            else if(map[nx][ny] == 'v') v_count++;

            q.push({nx, ny});
            visit[nx][ny]++;
        }
    }

    if(o_count > v_count) o_all += o_count;
    else v_all += v_count;
}

int main(void)
{
    Input();
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(visit[i][j] == 0 && map[i][j] != '#')
                Bfs(i, j);
        }
    }

    cout << o_all << " " << v_all;
}