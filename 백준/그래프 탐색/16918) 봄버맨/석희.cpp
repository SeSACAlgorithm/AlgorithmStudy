// 문제 분석
/*
    R * C (격자 칸 비어있거나(.) 폭탄(o))
    폭탄 - 3초가 지나면 폭발 (있던 칸 & 주변칸 파괴 (폭탄이 있는 경우 폭발 없이 파괴))

    1. 일부 칸 폭탄 설치
    2. 1초 동안 아무것도 안함
    3. 설치되어 있지 않은 모든 칸 폭탄 설치
    4. 처음 설치한 폭탄 폭발

    => N초가 흐른 후의 격자판 상태 출력
*/

#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int R, C, N;
char map[201][201];
int dx[4] = {0,0,-1, 1};
int dy[4] = {-1,1,0,0};

void input()
{
    char input_c;

    cin >> R >> C >> N;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> input_c;
            map[i][j] = input_c;
        }
    }
}

void output()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(map[i][j] == 'x') map[i][j] = 'O';
            cout << map[i][j];
        }
        cout << "\n";
    }
}


void bfs(bool flag)
{
    bool visit[201][201] = {false, };
    set<pair<int, int>> temp_map; // 중복 방지를 위해 set 사용
    queue<pair<int, int>> q;

    q.push({0,0});
    visit[0][0] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 주변을 터트릴 수 있는 폭탄이라면
        if((flag && map[x][y] == 'O') || (!flag && map[x][y] == 'x'))
        {
            // set에 해당 좌표 넣기
            temp_map.insert({x, y});

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                temp_map.insert({nx, ny});
            }
        }

        // bfs 돌기
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(visit[nx][ny]) continue;

            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }

    for(auto it  = temp_map.begin(); it != temp_map.end(); it++)
    {
        map[it->first][it->second] = '.';
    }
}

void fill_map(bool flag)
{
    // true면 o로 표시 false면 x로 표시
    char bomb = flag ? 'O' : 'x';
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(map[i][j] == '.') map[i][j] = bomb;
        }
    }
}

void solve()
{
    int time = 0;
    bool flag = false;       // o으로 표시할건지(true) x로 표시할건지(false) 나타내는 flag
    int temp_bomb = 3;      // 폭발이 터지는 타이밍 (3, 5, 7, 9, ...)

    while(time != N)
    {
        time++;

        // 처음 1초는 아무것도 하지 않음
        if(time == 1) continue;

        // 설치되어 있지 않은 모든 칸에 폭탄 설치
        else if(time % 2 == 0)
        {
            fill_map(flag);
            flag = !flag;
        }

        // 폭발
        else if(time == temp_bomb)
        {
            temp_bomb = temp_bomb + 2;
            bfs(flag);  // true라면 o터짐, false라면 x터짐
        }
    }
}

int main(void)
{
    input();
    solve();
    output();
}