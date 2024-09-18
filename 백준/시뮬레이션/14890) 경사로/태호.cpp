#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, len, result = 0;

int board[105][105];
bool road[105][105];

bool MakeRoad(int r, int c, bool isLeft)
{

    if (isLeft)
    {
        if (c - len < 0)
            return false;

        for (int i = c - 1; i >= c - len; --i)
        {
            if (road[r][i] || board[r][i] != board[r][c - 1])
                return false;

            road[r][i] = true;
        }

    }
    else
    {

        if (c + len > n)
            return false;

        for (int i = c; i < c + len; ++i)
        {
            if (road[r][i] || board[r][i] != board[r][c])
                return false;

            road[r][i] = true;
        }
    }

    return true;
}
bool MakeRoadRow(int r, int c, bool isUp)
{

    if (isUp)
    {
        if (r - len < 0)
            return false;

        for (int i = r - 1; i >= r - len; --i)
        {
            if (road[i][c] || board[i][c] != board[r - 1][c])
                return false;

            road[i][c] = true;
        }

    }
    else
    {

        if (r + len > n)
            return false;

        for (int i = r; i < r + len; ++i)
        {
            if (road[i][c] || board[i][c] != board[r][c])
                return false;

            road[i][c] = true;
        }
    }

    return true;
}


void ColumRoad()
{
    // 가로로 움직인다.
    // 왼쪽이나 오른쪽이 1이하라면 경사로를 만들어준다.
    // 이미 경사로를 설치했다면 만들 수 없다. break;
    // 다음 인덱스로 넘어간다.
    // 이전 인덱스의 값을 저장한다.


    for (int i = 0; i < n; ++i)
    {
        int left = board[i][0];
        bool cond = false;

        for (int j = 1; j < n; ++j)
        {
            bool isLeft = left < board[i][j] ? true : false;

            if(board[i][j] >= left + 2 || board[i][j] <= left - 2) 
            {
                cond = true;
                break;
            }
            else if (board[i][j] == left + 1 || board[i][j] == left - 1)
            {
                if (!MakeRoad(i, j, isLeft))
                {
                    cond = true;
                    break;
                }
            }
            
            left = board[i][j];
        }

        if(!cond)
            ++result;
    }
}

void RowRoad()
{
    for (int j = 0; j < n; ++j)
    {
        int up = board[0][j];
        bool cond = false;

        for (int i = 1; i < n; ++i)
        {
            bool isUp = up < board[i][j] ? true : false;

            if (board[i][j] >= up + 2 || board[i][j] <= up - 2)
            {
                cond = true;
                break;
            }
            else if (board[i][j] == up + 1 || board[i][j] == up - 1)
            {
                if (!MakeRoadRow(i, j, isUp))
                {
                    cond = true;
                    break;
                }
            }

            up = board[i][j];
        }

        if (!cond)
            ++result;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> len;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> board[i][j];
    
    ColumRoad();

    for(int i = 0; i < n; ++i)
        fill(road[i], road[i] + n, false);

    RowRoad();
            
    cout << result;
}
