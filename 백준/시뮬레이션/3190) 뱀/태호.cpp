#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, l;
int r, c;

int board[102][102];
int body[102][102];

int dist = 0;

queue<pair<int, char>> rotateInfo;

enum ECoord
{
    Right,
    Down,
    Left,
    Up
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> n >> k;
    

    for (int i = 0; i < k; ++i)
    {
         cin >> r >> c;
        board[r - 1][c - 1] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; ++i)
    {
        int seconds; char dir;
        cin >> seconds >> dir;
        rotateInfo.push({seconds, dir});
    }

    int direction = Right;

    r = 0; c = 0;

    queue<pair<int, int>> preQue;
    preQue.push({0, 0});

    while (true)
    {
        if(r == -1 || c == -1 || r == n || c == n) break;
        if(body[r][c]) break;

        if (board[r][c] != 1)
        {
            auto cur = preQue.front();
            preQue.pop();

            body[cur.first][cur.second] = false;
        }
        else
            board[r][c] = 0;
        
        body[r][c] = true;
        preQue.push({r, c});

        if (!rotateInfo.empty())
        {
            auto cur = rotateInfo.front();

            if (cur.first == dist)
            {
                if(cur.second == 'D')
                    direction = (direction + 1) % 4;

                if (cur.second == 'L')
                {
                    if(--direction == -1)
                        direction = Up;
                }
                
                rotateInfo.pop();
            }
        }

        ++dist;
        
        if(direction == Right)
            ++c;
        else if(direction == Left)
            --c;
        else if (direction == Up)
            --r;
        else if (direction == Down)
            ++r;
        
    }

    cout << dist;

}
