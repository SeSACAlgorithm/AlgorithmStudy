#include <bits/stdc++.h>

using namespace std;

int result = 0;


struct FStr
{
    int size, dir;
};

struct FShark
{
    int x = 0, y = 0, dir;
};

enum EDirection
{
    None,
    Up,
    UpLeft,
    Left,
    DownLeft,
    Down,
    DownRight,
    Right,
    UpRight
};


FShark sharkPos;
FStr board[4][4];
bool visited[4][4];

bool Search()
{
    return true;
}

pair<int, int> Find(int size)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(board[i][j].size == size)
                return {i, j};
        }
    }
}

pair<int, int> MakeDir(int dir)
{
    if (dir == Up)
    {
        return { -1, 0 };
    }
    else if (dir == UpLeft)
    {
        return { -1, -1 };
    }
    else if (dir == Left)
    {
        return { 0, -1 };
    }
    else if (dir == DownLeft)
    {
        return { 1, -1 };
    }
    else if (dir == Down)
    {
        return { 1, 0 };
    }
    else if (dir == DownRight)
    {
        return { 1, 1 };
    }
    else if (dir == Right)
    {
        return { 0, 1 };
    }
    else if (dir == UpRight)
    {
        return { -1, 1 };
    }
}

void MoveFish()
{
    map<int, int> m;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if(board[i][j].size != 0)
                m.emplace(board[i][j].size, board[i][j].dir);


    for (auto iter : m)
    {
        int size = iter.first;
        int dir = iter.second;

        pair<int, int> current = Find(size);
        //cout << size << "번째 물고기가 움직임\n";

        if(size == 6)
            int a = 0;

        for (int k = 0; k < 8; ++k)
        {
            
            pair<int, int> mkDir = MakeDir(dir);

            int x = current.first + mkDir.first;
            int y = current.second + mkDir.second;

            if ((x < 0 || y < 0 || x >= 4 || y >= 4) || (sharkPos.x == x && sharkPos.y == y))
            {
                if (++dir == 9)
                    dir = 1;

                continue;
            }
            
            //cout << board[x][y].size << "번째 물고기와 자리를 바꿈\n";

            board[current.first][current.second].dir = dir;
            swap(board[current.first][current.second], board[x][y]);
            //board[current.first][current.second].dir = dir;
            
 /*           cout  <<"--------------------------물고기 모양------------------------\n";
            

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (board[i][j].size == 0)
                        cout << "empty, ";
                    else
                        cout << "{" << board[i][j].size << ", " << board[i][j].dir << "}, ";
                }
                cout << '\n';
            }*/

            

            break;
        }
    }

    //cout << "현재 상어 위치 : x -> " << sharkPos.x << " y -> " << sharkPos.y << "\n\n";

    //for (int i = 0; i < 4; ++i)
    //{
    //    for (int j = 0; j < 4; ++j)
    //    {
    //        if (board[i][j].size == 0)
    //            cout << "empty, ";
    //        else
    //            cout << "{" << board[i][j].size << ", " << board[i][j].dir << "}, ";
    //    }
    //    cout << '\n';
    //}

}


void BT(int x, int y, int total)
{
    result = max(result, total);
    
    FStr sub[4][4];
    MoveFish();
    memcpy(sub, board, sizeof(FStr) * 4 * 4);


    for (int i = 1; i <= 3; ++i)
    {
        pair<int, int> mkDir = MakeDir(sharkPos.dir);
        int nx = sharkPos.x + mkDir.first * i;
        int ny = sharkPos.y + mkDir.second * i;

        if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
            break;

        if (board[nx][ny].size != 0)
        {
            int currentSize = board[nx][ny].size;
            int oriDir = sharkPos.dir;
            board[nx][ny].size = 0;
            sharkPos.dir = board[nx][ny].dir;
            sharkPos.x = nx;
            sharkPos.y = ny;
            BT(nx, ny, total + currentSize);
            board[nx][ny].size = currentSize;
            sharkPos.dir = oriDir;
            sharkPos.x = x;
            sharkPos.y = y;
            memcpy(board, sub, sizeof(FStr) * 4 * 4);
        }
    }


 
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int size, dir; cin >> size >> dir;
            board[i][j].size = size;
            board[i][j].dir = dir;
        }
    }

    sharkPos.dir = board[0][0].dir;
    result = board[0][0].size;
    board[0][0].size = 0;

    BT(0, 0, result);

    cout << result;

    return 0;
}
