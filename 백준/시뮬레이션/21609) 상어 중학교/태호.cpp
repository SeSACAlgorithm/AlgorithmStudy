#include <bits/stdc++.h>

using namespace std;

int n, m, score = 0, biggerBlock = 0, rainbowMaxCnt = 0;
int board[21][21];
bool visited[21][21];
vector<pair<int, int>> group;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

// 블록 그룹은 연결된 블록의 집합이다. 그룹에는 일반 블록이 적어도 하나 있어야 하며, 일반 블록의 색은 모두 같아야 한다. 
// 검은색 포함 X 무지개 블록은 상관없음

// 그룹의 속한 블록 개수 >= 2, 즉 2개 이상 
// 임의의 한 블록에서 다른 모든 칸으로 이동 가능해야함(bfs)

// 블록 그룹의 기준 -> 블록 중에서 행의 번호가 가장 작은 블록
// 그러한 블록이 여러개면 열의 번호가 가장 작은 블록
// 무지개 블록이 아니여야함.

/*

    블록 그룹이 존재하는 동안 계속해서 반복되어야 한다.

    1. 
    크기가 가장 큰 블록 그룹을 찾는다. 
    그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹, 
    그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을, 
     그 것도 여러개이면 열이 가장 큰 것을 찾는다.

     2.  1에서 찾은 블록 그룹의 모든 블록을 제거한다. 블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.

    3. 격자에 중력이 작용한다.
    4. 격자가 90도 반시계 방향으로 회전한다.
    5. 다시 격자에 중력이 작용한다.

    격자에 중력이 작용하면 검은색 블록을 제외한 모든 블록이 행의 번호가 큰 칸으로 이동한다. 
    이동은 다른 블록이나 격자의 경계를 만나기 전까지 계속 된다.
*/

/*
*   의사코드
* 
    1. 이중 for문 으로 가장 큰 블록을 찾는다.
    2. 찾은 블록에서 그룹을 만들자.
    3. 무지개 수, 행, 열 모두 비교 후 그룹을 제거한다.
    4. 블록의 수 ^ 2를 하고 블록을 지운다.
    5. 중력을 작용시킨다. 검은색 블록은 움직이지 않는다.
    6. 격자를 90도 반시계 회전시킨다.
    7. 회전된 격자를 다시 중력을 적용시킨다. 마찬가지로 검은색 블록은 움직이지 않는다.
*/

void Input()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
}


void SearchBigBlock()
{
    biggerBlock = 0;
    rainbowMaxCnt= 0;

    for(int i = 0; i < 21; ++i)
        fill(visited[i], visited[i] + 21, false);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(board[i][j] <= 0 || visited[i][j]) continue;

            bool rainbowVisit[21][21] = {false};
            int rainbowCnt = 0;
            
            queue<pair<int, int>> que;
            vector<pair<int, int>> tmp;
            que.push({i, j});
            tmp.push_back({ i, j });
            visited[i][j] = true;

            while (!que.empty())
            {
                auto cur = que.front();
                que.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = dx[dir] + cur.first;
                    int ny = dy[dir] + cur.second;

                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(board[nx][ny] != 0 && board[nx][ny] != board[i][j]) continue;
                    if(rainbowVisit[nx][ny] || visited[nx][ny]) continue;

                    if (board[nx][ny] == 0)
                    {
                        ++rainbowCnt;
                        rainbowVisit[nx][ny] = true;
                    }
                    else
                        visited[nx][ny] = true;

                   
                    que.push({nx, ny});
                    tmp.push_back({nx, ny});
                }
            }


            if(biggerBlock > tmp.size() || tmp.size() < 2) continue;
            if(rainbowMaxCnt > rainbowCnt && tmp.size() == biggerBlock) continue;

            rainbowMaxCnt = rainbowCnt;
            biggerBlock = tmp.size();
            group = tmp;
        }
    }
}

void AddScore()
{
    for (int i = 0; i < group.size(); ++i)
    {
        auto[x, y] = group[i];
        board[x][y] = -2;
    }

    score += group.size() * group.size();

    group.clear();
}

void Change(int x, int y)
{
    for (int i = x; i < n - 1; ++i)
    {
        if (board[i + 1][y] != -2) break;

        swap(board[i + 1][y], board[i][y]);
    }
}

void UseGravity()
{
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(board[i][j] == -2 || board[i][j] == -1) continue;
            Change(i, j);
        }
    }
}

void Rotate()
{
    int sub[21][21];
    memcpy(sub, board, sizeof(int) * 21 * 21);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            board[i][j] = sub[j][n - 1 - i];
        }
    }


}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();

    while (true)
    {
        // 확인
        SearchBigBlock();

        if(biggerBlock == 0)
            break;

        // 획득
        AddScore();
        // 중력
        UseGravity();
        // 회전
        Rotate();
        // 중력
        UseGravity();
    }
    
    cout << score;

    return 0;
}
