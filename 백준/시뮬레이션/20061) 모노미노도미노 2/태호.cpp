#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, score = 0, cnt = 0;
bool board[10][10];
vector<vector<tuple<int, int, int>>> block;

// (0, 0) ~ (3, 3) 빨간 라인 y = 0, x = 0 시작

// (0, 4) ~ (3, 5) 하늘 라인 y = 4, x = 0 시작
// (0, 6) ~ (3, 9) 파랑 라인 y = 6, x = 0 시작

// (4, 0) ~ (5, 3) 연두 라인 y = 0, x = 4 시작
// (6, 3) ~ (9, 3) 초록 라인 y = 0, x = 6 시작

// 빨강 -> 임시

// 하늘 -> 세로줄 밀어내기
// 파랑 -> 세로줄 없앰(점수 획득)

// 연두 -> 가로줄 밀어내기
// 초록 -> 가로줄 없앰(점수 획득)

void Input()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int t, x, y; cin >> t >> x >> y;
        vector<tuple<int, int, int>> vec;

        vec.push_back({x, y, t});

        if (t == 2)
            vec.push_back({ x, y + 1, t });
        
        else if(t == 3)
            vec.push_back({ x + 1, y, t });

        block.push_back(vec);
    }
}

int BlockMove_Blue(int x, int y, vector<int> pos)
{
    int mn = 9;

    for (int i = 0; i < pos.size(); ++i)
    {
        for (int j = y; j < 10; ++j)
        {
            if (board[pos[i]][j])
            {
                mn = min(mn, j - 1);
                break;
            }
                
        }
    }

    return mn;
}

int BlockMove_Green(int x, int y, vector<int> pos)
{
    int mn = 9;

    for (int i = x; i < 10; ++i)
    {
        for (int j = 0; j < pos.size(); ++j)
        {
            if (board[i][pos[j]])
            {
                mn = min(mn, i - 1);
                break;
            }
           
        }
    }

    return mn;
}

void AddScore_Blue()
{
    int mn = 0;

    for (int j = 6; j < 10; ++j)
    {
        bool cond = true;

        // 4개가 차있는 지 비교
        for (int i = 0; i < 4; ++i)
        {
            if (!board[i][j])
            {
                cond = false;
                break;
            }
        }

        // 다 차있다면?
        if (cond)
        {
            mn = j;

            // 4개를 지우고 점수를 올리자
            for (int i = 0; i < 4; ++i)
                board[i][j] = false;

            for (int y = j - 1; y >= 4; --y)
            {
                for (int x = 0; x < 4; ++x)
                {
                    board[x][y + 1] = board[x][y];
                    board[x][y] = false;
                }
            }

            ++score;
        }
    }

}

void AddScore_Green()
{
    int mn = 0;

    for (int i = 6; i < 10; ++i)
    {
        bool cond = true;

        // 4개가 차있는 지 비교
        for (int j = 0; j < 4; ++j)
        {
            if (!board[i][j])
            {
                cond = false;
                break;
            }
        }

        // 다 차있다면?
        if (cond)
        {
            mn = i;

            // 4개를 지우고 점수를 올리자
            for (int j = 0; j < 4; ++j)
                board[i][j] = false;


            for (int x = i - 1; x >= 4; --x)
            {
                for (int y = 0; y < 4; ++y)
                {
                    board[x + 1][y] = board[x][y];
                    board[x][y] = false;
                }
            }

            ++score;
        }
    }
}

void AddScore()
{
    AddScore_Blue();
    AddScore_Green();
}

void PushBlcok_Blue()
{
    int push_cnt = 0;

    for (int j = 4; j < 6; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (board[i][j])
            {
                ++push_cnt;
                break;
            }
        }
    }

    // 3, 2, 1, 0
    // 4, 3, 2, 1
    if (push_cnt)
    {
        // 5 - 1 -> 4, 3, 2
        // 2 - 1 -> 1

        // 5 - 2 -> 3
        // 2 - 2 -> 0

        // 하나만 있다면?
        for (int j = 9 - push_cnt; j >= 6 - push_cnt; --j)
        {
            for (int i = 0; i < 4; ++i)
            {
                board[i][j + push_cnt] = board[i][j];
            }
            
        }

        for (int j = 5; j > 5 - push_cnt; --j)
            for (int i = 0; i < 4; ++i)
                board[i][j] = false;
    }
}

void PushBlcok_Green()
{
    int push_cnt = 0;

    for (int i = 4; i < 6; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j])
            {
                ++push_cnt;
                break;
            }
        }
    }

    // 3, 2, 1, 0
    // 4, 3, 2, 1
    if (push_cnt)
    {
        // 5 - 1 -> 4, 3, 2
        // 2 - 1 -> 1

        // 5 - 2 -> 3
        // 2 - 2 -> 0

        // 하나만 있다면?
        for (int i = 9 - push_cnt; i >= 6 - push_cnt; --i)
        {
            for (int j = 0; j < 4; ++j)
            {
                board[i + push_cnt][j] = board[i][j];
            }

        }

        for (int i = 5; i > 5 - push_cnt; --i)
            for (int j = 0; j < 4; ++j)
                board[i][j] = false;
    }
}

void PushBlcok()
{
    PushBlcok_Blue();
    PushBlcok_Green();
}

void InsertBlock()
{
    for (int i = 0; i < block.size(); ++i)
    {
        int minB = 100, minG = 100;

        vector<int> casese;
        vector<int> posB;
        vector<int> posG;

        for (int j = 0; j < block[i].size(); ++j)
        {
            auto [x, y, t] = block[i][j];
            casese.push_back(t);


            posB.push_back(x);
            posG.push_back(y);

            if (t == 3 && j == 1)
            {
                --minG;
                minB = min(minB, BlockMove_Blue(x, y, posB));
                continue;
            }
            else if (t == 2 && j == 1)
            {
                --minB;
                minG = min(minG, BlockMove_Green(x, y, posG));
            }
            else if (j == 0)
            {
                minB = min(minB, BlockMove_Blue(x, y, posB));
                minG = min(minG, BlockMove_Green(x, y, posG));
            }

        }


        auto [x, y, t] = block[i][0];

        if (t == 1)
        {
            board[x][minB] = true;
            board[minG][y] = true;
        }
        else if (t == 2)
        {
            board[x][minB] = true;
            board[x][minB + 1] = true;
            board[minG][y] = true;
            board[minG][y + 1] = true;
        }
        else if (t == 3)
        {
            board[x][minB] = true;
            board[x + 1][minB] = true;
            board[minG][y] = true;
            board[minG + 1][y] = true;
        }

        AddScore();
        PushBlcok();
    }


}

void Answer()
{
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (board[i][j])
                ++cnt;

    cout << score << '\n' << cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    InsertBlock();
    Answer();


    return 0;
}
