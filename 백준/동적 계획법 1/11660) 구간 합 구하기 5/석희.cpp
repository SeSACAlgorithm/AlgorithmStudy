#include <iostream>

using namespace std;

int N, M;
int map[1025][1025];
int DP[1025][1025];

void solve()
{
    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (DP[x2][y2] - DP[x1 - 1][y2] - DP[x2][y1 - 1] + DP[x1 - 1][y1 - 1]) << "\n";
    }
}

void input()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1] + map[i][j];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    solve();
}