// 빨간구슬을 빼내기
// 파란구슬은 구멍에 가면 안됨(파란 구슬 구멍에 빠지면 실패, 동시에 빠져도 실패)
// 빨간 구슬, 파란 구슬 같은 칸 X
// 최소 몇번만에 가능한지?

// 파란구슬이 빠지면 -1이 나와야함
// 동시에 빠지는거 무조건 생각!!
// *공이 겹치는 경우 무조건 생각해야함!!!*
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[11][11];

// visit[1][2] [4][5] = 1 -> 빨간색 구슬(1,2) / 파란색 구슬(4,5)에 있을 때 확인했다~
int visit[11][11][11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct node
{
    int rx, ry; // 빨간 공 좌표
    int bx, by; // 파란 공 좌표
    int count;  // 움직인 횟수
} node;

queue<node> q;

void solve(int srx, int sry, int sbx, int sby);
void input()
{
    cin >> N >> M;
    int rx, ry, bx, by;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                map[i][j] = 1; // 벽
            else if (c == '.')
                map[i][j] = 0; // 빈칸
            else if (c == 'O')
                map[i][j] = 2; // 구멍의 위치

            else if (c == 'R') // 빨간 공 위치
            {
                rx = i;
                ry = j;
            }
            else if (c == 'B') // 파란 공 위치
            {
                bx = i;
                by = j;
            }
        }
    }

    solve(rx, ry, bx, by);
}

void solve(int srx, int sry, int sbx, int sby)
{
    q.push({srx, sry, sbx, sby, 0});
    visit[srx][sry][sbx][sby]++;

    while (!q.empty())
    {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int count = q.front().count;
        q.pop();

        // 움직인 횟수가 10번 이상이라면 -1 출력
        // 초과가 아닌 이유 : 11번째에 성공하는 경우에 count > 10으로 되어있으면 11으로 답이 출력되어서 틀리게됨
        if (count >= 10)
            break;

        for (int i = 0; i < 4; i++)
        {
            // 쭉 가야하니까 먼저 dx, dy를 더해주면 안됨
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;

            while (true)
            {
                // 빈칸이라면
                if (map[nrx + dx[i]][nry + dy[i]] == 0)
                {
                    nrx += dx[i];
                    nry += dy[i];
                }

                // 구멍이라면
                else if (map[nrx + dx[i]][nry + dy[i]] == 2)
                {
                    nrx += dx[i];
                    nry += dy[i];
                    break;
                }

                // 벽이라면
                else if (map[nrx + dx[i]][nry + dy[i]] == 1)
                    break;
            }

            while (true)
            {
                // 빈칸이라면
                if (map[nbx + dx[i]][nby + dy[i]] == 0)
                {
                    nbx += dx[i];
                    nby += dy[i];
                }

                // 구멍이라면
                else if (map[nbx + dx[i]][nby + dy[i]] == 2)
                {
                    nbx += dx[i];
                    nby += dy[i];
                    break;
                }

                // 벽이라면
                else if (map[nbx + dx[i]][nby + dy[i]] == 1)
                    break;
            }

            // 파란구슬이 구멍에 빠진 경우
            if (map[nbx][nby] == 2)
                continue;

            // 빨간 구슬이 구멍에 빠진 경우
            if (map[nrx][nry] == 2)
            {
                cout << count + 1;
                return;
            }

            // 구슬끼리 겹친 경우
            if (nrx == nbx && nry == nby)
            {
                int rdist = abs(nrx - rx) + abs(nry - ry);
                int bdist = abs(nbx - bx) + abs(nby - by);

                // 빨간 구슬이 더 멀리서 온 경우
                if (rdist > bdist)
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }

                // 파란 구슬이 더 멀리서 온 경우
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            // 빨간 구슬이랑 파란 구슬이 다 굴러간 위치가 방문했던 적이 있다면
            if (visit[nrx][nry][nbx][nby] != 0)
                continue;

            q.push({nrx, nry, nbx, nby, count + 1});
            visit[nrx][nry][nbx][nby]++;
        }
    }

    // 10번이 넘었거나 아예 빼낼 수 없는 경우
    cout << "-1";
}

int main(void)
{
    input();
}