#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int n, treeNum, year, result = 0;
int S2D2[11][11];
int board[11][11];

deque<int> trees[11][11];
vector<tuple<int, int, int>> dead;
vector<pair<int, int>> create;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 나무가 자신의 나이만큼 양분을 먹고 나이가 1 증가
// 하나의 칸에 여러 개의 나무가 있다면 어린 나무부터 양분을 먹는다
// 만약 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 죽는다.

void DeadTrees(deque<int>& deq, int index, int x, int y)
{
    while(deq.size() > index)
    {
        dead.push_back({ x, y, deq[deq.size() - 1] / 2});
        deq.pop_back();
    }
}

void Spring()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 0; k < trees[i][j].size(); ++k)
            {
                board[i][j] -= trees[i][j][k];

                if (board[i][j] < 0)
                {
                    board[i][j] += trees[i][j][k];
                    DeadTrees(trees[i][j], k, i, j);
                    break;
                }

                ++trees[i][j][k];

                if (trees[i][j][k] % 5 == 0)
                    create.push_back({ i, j });
            }
        }
    }
}

// 봄에 죽은 나무가 양분으로 변하게 된다.
// 죽은 나무마다 나이를 2로 나눈 값(나이 / 2) 나무가 있던 칸에 양분으로 추가된다.
void Summer()
{
    for (int i = 0; i < dead.size(); ++i)
    {
        auto [x, y, age] = dead[i];
        board[x][y] += age;
    }

    dead.clear();
}

// 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 한다.
// 인접칸 8개에 나이가 1인 나무가 생긴다.
void Fall()
{
    for (int i = 0; i < create.size(); ++i)
    {
        auto [x, y] = create[i];

        for (int dir = 0; dir < 8; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;

            // 경계 체크를 수정 (1-based 인덱스)
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            trees[nx][ny].push_front(1);
        }
    }

    create.clear();
}

// 땅에 양분을 추가한다.
void Winter()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            board[i][j] += S2D2[i][j];
        }
    }
}

void Solve()
{
    while (year--)
    {
        Spring();
        Summer();
        Fall();
        Winter();
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            result += trees[i][j].size();

    cout << result;
}

void Setting()
{
    cin >> n >> treeNum >> year;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> S2D2[i][j];
            board[i][j] = 5;
        }
    }

    while (treeNum--)
    {
        int x, y, age; cin >> x >> y >> age;
        trees[x][y].push_back(age);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (trees[i][j].size() > 1)
                sort(trees[i][j].begin(), trees[i][j].end());
        }
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Setting();
    Solve();

    return 0;
}
