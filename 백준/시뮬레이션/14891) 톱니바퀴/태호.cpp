#include <iostream>
#include <vector>

using namespace std;

string board[8];

int k;

// 2 오른쪽 맞닿아있는 극
// 6 왼쪽 맞닿아있는 극 

void Solve(int boardNum, int clock, bool visit[], vector<pair<int, int>>& vec)
{
    vec.push_back({boardNum, clock});
    visit[boardNum] = true;

    if(boardNum == 0)
    {
        if (!visit[boardNum + 1] && board[0][2] != board[1][6])
            Solve(boardNum + 1, clock == 1 ? -1 : 1, visit, vec);
    }

    if (boardNum == 1)
    {
        if (!visit[boardNum - 1] && board[0][2] != board[1][6])
            Solve(boardNum - 1, clock == 1 ? -1 : 1, visit, vec);

        if (!visit[boardNum + 1] && board[1][2] != board[2][6])
            Solve(boardNum + 1, clock == 1 ? -1 : 1, visit, vec);
    }

    if (boardNum == 2)
    {
        if (!visit[boardNum - 1] && board[1][2] != board[2][6])
            Solve(boardNum - 1, clock == 1 ? -1 : 1, visit, vec);

        if (!visit[boardNum + 1] && board[2][2] != board[3][6])
            Solve(boardNum + 1, clock == 1 ? -1 : 1, visit, vec);
    }

    if (boardNum == 3)
    {
        if (!visit[boardNum - 1] && board[2][2] != board[3][6])
            Solve(boardNum - 1, clock == 1 ? -1 : 1, visit, vec);
    }

}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; ++i)
        cin >> board[i];

    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int boardNum, clock;
        vector<pair<int, int>> vec;
        bool visit[4] = {false};
        cin >> boardNum >> clock;
        Solve(boardNum - 1, clock, visit, vec);

        for (auto cur : vec)
        {
            if (cur.second == -1)
                board[cur.first] = string(board[cur.first].begin() + 1, board[cur.first].begin() + 8) + board[cur.first][0];

            else
                board[cur.first] = board[cur.first][7] + string(board[cur.first].begin(), board[cur.first].begin() + 7);
        }
    }

    int result = 0;

    for(int i = 0; i < 4; ++i)
        if(board[i][0] == '1')
            result += (1<<i);

    cout << result;
}
