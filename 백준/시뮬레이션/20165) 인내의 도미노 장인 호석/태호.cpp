#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct FAttack
{
    int x, y;
    char d;
};

struct FDefence
{
    int x, y;
};

int n, m, r, score = 0;

int board[101][101];
int Oriboard[101][101];
vector<FAttack> Attacker;
vector<FDefence> Denfender;

void Input()
{
    cin >> n >> m >> r;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> Oriboard[i][j];
            board[i][j] = Oriboard[i][j];
        }
    }

    for (int i = 0; i < r; ++i)
    {
        int x, y;
        char d;
        cin >> x >> y >> d;

        Attacker.push_back({ --x, --y, d });

        cin >> x >> y;

        Denfender.push_back({--x, --y});
    }

}

void Attack(int index)
{
    auto [x, y, d] = Attacker[index];

    if (board[x][y] == -1) return;

    int brokenCnt = board[x][y] - 1;
    board[x][y] = -1;
    ++score;

    if (d == 'E')
    {
        for (int i = y + 1; i < m && brokenCnt > 0; ++i)
        {
            if (board[x][i] != -1)
            {
                brokenCnt = max(brokenCnt, board[x][i]);
                board[x][i] = -1;
                ++score;
            }
            
            --brokenCnt;
            
        }
    }
    if (d == 'W')
    {
        for (int i = y - 1; i >= 0 && brokenCnt > 0; --i)
        {
            if (board[x][i] != -1)
            {
                brokenCnt = max(brokenCnt, board[x][i]);
                board[x][i] = -1;
                ++score;
            }
            
            --brokenCnt;
            
        }
    }
    else if (d == 'S')
    {
        for (int i = x + 1; i < n && brokenCnt > 0; ++i)
        {
            if (board[i][y] != -1)
            {
                brokenCnt = max(brokenCnt, board[i][y]);
                board[i][y] = -1;
                ++score;
            }

            
            --brokenCnt;
            
        }
    }
    else if (d == 'N')
    {
        for (int i = x - 1; i >= 0 && brokenCnt > 0; --i)
        {
            if (board[i][y] != -1)
            {
                brokenCnt = max(brokenCnt, board[i][y]);
                board[i][y] = -1;
                ++score;
            }

            --brokenCnt;
            
        }
    }


}

void Defence(int index)
{
    auto [x, y] = Denfender[index];

    board[x][y] = Oriboard[x][y];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Input();

    for (int i = 0; i < r; ++i)
    {
        Attack(i);
        Defence(i);
    }

    cout << score << '\n';

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(board[i][j] == -1)
                cout << "F ";
            else
                cout << "S ";
        }

        cout << '\n';
    }
    

    return 0;
}
