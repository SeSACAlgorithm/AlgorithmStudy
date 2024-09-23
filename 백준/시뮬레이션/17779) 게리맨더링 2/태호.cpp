#include <iostream>
#include <algorithm>

using namespace std;

int n, result = 0x7f7f7f7f;
int board[21][21];
int garry[21][21];

void Solve(int r, int c, int d1, int d2)
{
    for (int k = 0; k < 21; ++k)
        fill(garry[k], garry[k] + 21, 0);

    if (r + d1 >= n || c - d1 < 0 || r + d2 >= n || c + d2 >= n || r + d1 + d2 >= n || c - d1 + d2 < 0)
        return;

    int x1 = r, y1 = c;
    for (int i = 0; i <= d1; ++i) garry[x1 + i][y1 - i] = 5;
    int x2 = r, y2 = c;
    for (int i = 0; i <= d2; ++i) garry[x2 + i][y2 + i] = 5;
    for (int i = 0; i <= d2; ++i) garry[r + d1 + i][c - d1 + i] = 5;
    for (int i = 0; i <= d1; ++i) garry[r + d2 + i][c + d2 - i] = 5;

    for (int i = r + 1; i < r + d1 + d2; ++i)
    {
        bool flag = false;
        for (int j = 0; j < n; ++j)
        {
            if (garry[i][j] == 5) flag = !flag;
            if (flag) garry[i][j] = 5;
        }
    }


    for (int i = 0; i < r + d1; ++i)
        for (int j = 0; j <= c; ++j)
            if (garry[i][j] == 0) garry[i][j] = 1;


    for (int i = 0; i <= r + d2; ++i)
        for (int j = c + 1; j < n; ++j)
            if (garry[i][j] == 0) garry[i][j] = 2;


    for (int i = r + d1; i < n; ++i)
        for (int j = 0; j < c - d1 + d2; ++j)
            if (garry[i][j] == 0) garry[i][j] = 3;


    for (int i = r + d2 + 1; i < n; ++i)
        for (int j = c - d1 + d2; j < n; ++j)
            if (garry[i][j] == 0) garry[i][j] = 4;


    int sum[6] = { 0 };

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum[garry[i][j]] += board[i][j];

    sum[5] += sum[0];  
    sum[0] = 0;


    int mx = -1, mn = 0x7f7f7f7f;

    for (int i = 1; i <= 5; ++i)
    {
        mx = max(mx, sum[i]);
        mn = min(mn, sum[i]);
    }

    result = min(result, mx - mn);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int d1 = 1; d1 < n; ++d1)
                for (int d2 = 1; d2 < n; ++d2)
                    Solve(i, j, d1, d2);


    cout << result;

    return 0;
}
