#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, result = 0;
bool board[102][102];

/*

1세대 : 0 뒤집기 -> 01
2세대 : 01 뒤집기 -> 01 (21)
3세대 : 0121 뒤집기 -> 0121(2321)

1세대 : 1 뒤집기 -> 12
2세대 : 12 뒤집기 -> 12(32)
3세대 : 1232 뒤집기 -> 1232(3032)

*/

void Answer()
{
    for (int i = 0; i <= 100; ++i) 
        for (int j = 0; j <= 100; ++j) 
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                result++;
            

    cout << result;
}

vector<tuple<int, int, int, int>> curves;
vector<int> storeDir;

int moveX[4] = { 0,-1,0,1 };
int moveY[4] = { 1,0,-1,0 };

bool Move(int& x, int& y, int dir, bool insert)
{
    x += moveX[dir];
    y += moveY[dir];

    if(x > 100 || y > 100 || x < 0 || y < 0) return false;
    
    if(insert)
        board[x][y] = true;

    return true;
}

void AddCurve(int x, int y, int generate_curve, int& pre)
{
    for (int i = 0; i < generate_curve; ++i)
    {
        for (int c = (1 << i) - 1; c >= 0; --c)
        {
            storeDir.push_back((storeDir[c] + 1) % 4);

            if (!Move(x, y, storeDir.back(), false))
                return;
        }

        pre = (1 << i + 1);
    }
}

void Solve()
{
    for (int i = 0; i < curves.size(); ++i)
    {
        auto [x, y, dir, generate_curve] = curves[i];
        int pre = 1, checkX = x, checkY = y;
        bool cond = false;

        storeDir.clear();

        if(!Move(checkX, checkY, dir, false))
            continue;

        storeDir.push_back(dir);
        board[x][y] = true;

        AddCurve(checkX, checkY, generate_curve, pre);

        for (int j = 0; j < pre; ++j)
            Move(x, y, storeDir[j], true);
    }
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x, y, d, g; cin >> x >> y >> d >> g;
        curves.push_back({y, x, d, g});
    }

    Solve();
    Answer();

    return 0;
}
