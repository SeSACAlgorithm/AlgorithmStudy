#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

constexpr int st = 1;
constexpr int en = 2;

int n, m, h, result = 4;
int board[303][12];

bool Search()
{
    for (int i = 0; i < n; ++i)
    {
        int height = 0, width = i;
        
        while (height < h)
        {
            if (width < n - 1 && board[height][width] == st && board[height][width + 1] == en)
                ++width;
                
            else if (width > 0 && board[height][width] == en && board[height][width - 1] == st)
                --width;

            ++height;
        }

        if(i != width)
            return false;
    }


    return true;
}

void Solve(int cur, int x, int y)
{
    if(cur == result)
        return;

    if (Search())
    {
        result = min(result, cur);
        return;
    }

    if(cur == 3)
        return;

    for (int height = x; height < h; ++height, y = 0)
    {
        for (int width = y; width < n; ++width)
        {
            if(board[height][width] == st || board[height][width] == en || board[height][width + 1] == st) continue;
        
            board[height][width] = st;
            board[height][width + 1] = en;
            Solve(cur + 1, height, width + 2);
            board[height][width] = 0;
            board[height][width + 1] = 0;

        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        board[a - 1][b - 1] = st;
        board[a - 1][b] = en;
    }

    if (m != 0)
        Solve(0, 0, 0);

    else
        if(Search())
            result = 0;

    result > 3 ? cout << -1 : cout << result;

}
