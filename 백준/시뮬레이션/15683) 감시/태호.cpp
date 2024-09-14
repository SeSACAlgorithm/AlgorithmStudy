#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[10][10];
int arr[10][10];

enum coord
{
    LEFT,
    TOP,
    RIGHT,
    BOTTOM,
    END
};

struct STR
{
    int x, y, coo;
};

vector<STR> brute;
int result = 0x7f7f7f7f;

void Left(int x, int y)
{
    for (int i = y - 1; i >= 0; --i)
    {
        if (arr[x][i] == 6) break;
        arr[x][i] = 7;
    }
}

void Top(int x, int y)
{
    for (int i = x - 1; i >= 0; --i)
    {
        if (arr[i][y] == 6) break;
        arr[i][y] = 7;
    }
}

void Right(int x, int y)
{
    for (int i = y + 1; i < m; ++i)
    {
        if (arr[x][i] == 6) break;
        arr[x][i] = 7;
    }
}


void Bottom(int x, int y)
{
    for (int i = x + 1; i < n; ++i)
    {
        if (arr[i][y] == 6) break;
        arr[i][y] = 7;
    }
}


void One(vector<STR> vec, int index, int x, int y)
{
    if (vec[index].coo == LEFT)
        Left(x, y);

    else if (vec[index].coo == TOP)
        Top(x, y);


    else if (vec[index].coo == RIGHT)
        Right(x, y);

    else if (vec[index].coo == BOTTOM)
        Bottom(x, y);

}

void Two(vector<STR> vec, int index, int x, int y)
{
    if (vec[index].coo == LEFT || vec[index].coo == RIGHT)
    {
        Left(x, y);
        Right(x, y);
    }


    if (vec[index].coo == TOP || vec[index].coo == BOTTOM)
    {
        Top(x, y);
        Bottom(x, y);
    }
}

void Three(vector<STR> vec, int index, int x, int y)
{
    if (vec[index].coo == LEFT)
    {
        Left(x, y);
        Top(x, y);
    }
    else if (vec[index].coo == TOP)
    {
        Top(x, y);
        Right(x, y);
    }
    else if (vec[index].coo == RIGHT)
    {
        Right(x, y);
        Bottom(x, y);
    }
    else if (vec[index].coo == BOTTOM)
    {
        Bottom(x, y);
        Left(x, y);
    }
}

void Four(vector<STR> vec, int index, int x, int y)
{
    if (vec[index].coo == LEFT)
    {
        Left(x, y);
        Top(x, y);
        Right(x, y);
    }
    else if (vec[index].coo == TOP)
    {
        Top(x, y);
        Right(x, y);
        Bottom(x, y);
    }
    else if (vec[index].coo == RIGHT)
    {
        Right(x, y);
        Bottom(x, y);
        Left(x, y);
    }
    else if (vec[index].coo == BOTTOM)
    {
        Bottom(x, y);
        Left(x, y);
        Top(x, y);
    }
}

void Five(vector<STR> vec, int index, int x, int y)
{
    Left(x, y);
    Top(x, y);
    Right(x, y);
    Bottom(x, y);
}

void Solve(int cur, vector<STR> vec)
{
    if (cur == brute.size())
    {

        for (int i = 0; i < n; ++i)
            memcpy(arr[i], board[i], sizeof(int) * m);

        for (int k = 0; k < vec.size(); ++k)
        {
            int x = vec[k].x;
            int y = vec[k].y;

            int num = board[x][y];

            if (num == 1)
            {
                One(vec, k, x, y);
            }
            else if (num == 2)
            {
                Two(vec, k, x, y);
            }
            else if (num == 3)
            {
                Three(vec, k, x, y);
            }
            else if (num == 4)
            {
                Four(vec, k, x, y);
            }
            else if (num == 5)
            {
                Five(vec, k, x, y);
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!arr[i][j])
                    ++cnt;

        result = min(result, cnt);
        return;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        STR tmp = brute[cur];
        tmp.coo = dir;
        vec.push_back(tmp);
        Solve(cur + 1, vec);
        vec.pop_back();
    }
}



int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] != 0 && board[i][j] != 6)
                brute.push_back({ i, j });
        }
    }

    Solve(0, vector<STR>());
    cout << result;
}


