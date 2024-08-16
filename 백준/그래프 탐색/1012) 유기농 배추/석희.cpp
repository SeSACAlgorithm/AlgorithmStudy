// 문제 분석
/*
  1. 지렁이가 있는 배추의 근처 배추는 안전 (상하좌우)
  2. 배추 심어져 있지 않은 땅 0 / 배추 심어져 있는 땅 1
  총 몇마리 지렁이가 필요?

  입력
  T     : 테스트 케이스의 개수
  M     : 배추를 심은 배추밭의 가로 길이
  N     : 배추를 심은 배추밭의 세로 길이
  K     : 배추가 심어져 있는 위치의 개수
  X, Y  : 배추의 위치
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[51][51] = {
    0,
};
bool visit[51][51] = {
    false,
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int T, M, N, K, X, Y;

void solve(int x, int y)
{
    queue<pair<int, int>> _q_cabbage;

    _q_cabbage.push({x, y});
    visit[y][x] = true;

    while (!_q_cabbage.empty())
    {
        int x = _q_cabbage.front().first;
        int y = _q_cabbage.front().second;
        _q_cabbage.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵 범위 밖인 경우
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

            // 이미 확인한 곳인 경우
            if (visit[ny][nx]) continue;

            // 배추가 있다면
            if (map[ny][nx] == 1)
            {
                visit[ny][nx] = true;
                _q_cabbage.push({nx, ny});
            }
        }
    }
}

void input()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;

        int answer = 0;
        queue<pair<int, int>> q_cabbage;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));

        for (int j = 0; j < K; j++)
        {
            cin >> X >> Y;
            map[Y][X] = 1;
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (map[y][x] == 1 && !visit[y][x])
                {
                    solve(x, y);
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }
}

int main(void)
{
    input();
}