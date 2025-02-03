// 문제 분석
/*
    1. 마법 벽(1)은 통과할 수 없음
    2. 그람(2)을 획득한다면 마법 벽(1)도 통과 가능
    
    => 바로 공주님이 있는 곳으로 가는 방법 VS 그람을 얻고 마법 벽 모두 무시하고 가는 방법
    구해서 최솟값 찾기
    만약 이 값이 T보다 크다면 false 출력

    공주님은 항상 맵의 끝에 위치
*/

#define MAX_NM 100
#define MAX_TIME 10000

#include <iostream>
#include <queue>

using namespace std;

int N, M, T;           // 맵 크기 & 제한 시간

int map[MAX_NM][MAX_NM];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int gram[2];

void Input()
{
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if(map[i][j] == 2) 
            {
                gram[0] = i;
                gram[1] = j;
            }
        }
    }
}

int Bfs(int ex, int ey)
{
    int visit[MAX_NM][MAX_NM] = {0, };

    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = 1;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == ex && y == ey) return visit[ex][ey] - 1;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 벽이라서 못가는 경우
            if(map[nx][ny] == 1) continue;

            if(visit[nx][ny] != 0) continue;

            visit[nx][ny] = visit[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return MAX_TIME + 1;
}

void Solve()
{
    // 그람을 구하고 공주를 구하는 경우
    int findGram = Bfs(gram[0], gram[1]);
    findGram = findGram + abs(gram[0] - (N - 1)) + abs(gram[1] - (M - 1));
    // cout << "g : " << findGram << "\n";

    // 바로 공주한테 가는 경우
    int findPrincess = Bfs(N-1, M-1);
    // cout << "p : " << findPrincess << "\n";

    int answer = min(findGram, findPrincess);
    if(answer <= T) cout << answer;
    else cout << "Fail";
}

int main(void)
{
    Input();
    Solve();
}