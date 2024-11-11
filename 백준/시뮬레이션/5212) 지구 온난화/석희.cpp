#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int r, c;
char map[10][10];
char copyMap[10][10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int minX = 10;
int minY = 10;
int maxX = 0;
int maxY = 0;

void Input()
{
    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            copyMap[i][j] = map[i][j];
        }
    }
}

void FindOcean(int sx, int sy)
{
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = dx[i] + sx;
        int ny = dy[i] + sy;

        if(nx < 0 || ny < 0 || nx >= r || ny >= c)
        {
            count++;
            continue;
        }

        if(map[nx][ny] == '.') count++;
    }

    if(count >= 3)
    {
        copyMap[sx][sy] = '.';
    }
}

void FindRange()
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(copyMap[i][j] == 'X')
            {
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }
}

void Solve()
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == 'X') FindOcean(i, j);
        }   
    }

    FindRange();
}

void Output()
{
    for(int i = minX; i <= maxX; i++)
    {
        for(int j = minY; j <= maxY; j++)
        {
            cout << copyMap[i][j];
        }
        cout << '\n';
    }
}

int main(void)
{
    Input();
    Solve();
    Output();
}