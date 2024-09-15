#include <iostream>

using namespace std;

int board[22][22];

int n, m, x, y, k;

enum Coord
{
    NONE,
    East,
    West,
    North,
    South,
};

int dice[6] = {0};


/*

1 위
2 앞
3 오른
4 왼
5 뒤
6 아래

pseudo code(문제 지문이 어려워 작성함.)
if(주사위를 이동했을 때(동서남북) 이동한 칸에 쓰에있는 수가 0이면?)
    주사위의 바닥면에 쓰여있는 수가 칸에 복사됨
else 0이 아닌 경우
    칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 
    칸에 쓰여 있는 수는 0이 된다. 

swap을 이용해 구현하자.
West에서 swap 하는 방법

    2
  4 1 3
    5
    6
  
    2
  4 6 3
    5
    1
  
    2
  4 3 6
    5
    1
  
    2
  1 3 6
    5
    4

   물건을 직접 회전하며 기하학적인 부분들을 고려했다.
*/

void ResetDice()
{
    if (board[x][y] == 0)
    {
        board[x][y] = dice[5];
    }
    else
    {
        dice[5] = board[x][y];
        board[x][y] = 0;
    }
}

// swap을 이용해 구현
void ChangeDice(Coord dir)
{   
    if (dir == East)
    {
        if (y + 1 == m)
            return;

        ++y;

        swap(dice[0], dice[5]);
        swap(dice[0], dice[3]);
        swap(dice[2], dice[5]);
    }

    else if (dir == West)
    {
        if (y == 0)
            return;

        --y;

        swap(dice[0], dice[5]);
        swap(dice[0], dice[2]);
        swap(dice[3], dice[5]);
    }

    else if (dir == North)
    {
        if (x == 0)
            return;

        --x;
        swap(dice[0], dice[4]);
        swap(dice[4], dice[5]);
        swap(dice[1], dice[5]);
    }

    else if (dir == South)
    {
        if (x + 1 == n)
            return;

        ++x;
        swap(dice[0], dice[4]);
        swap(dice[0], dice[1]);
        swap(dice[1], dice[5]);
    }

    ResetDice();
    cout << dice[0] << '\n';

}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    }

    for (int i = 0; i < k; ++i)
    {
        int dir; cin >> dir;
        ChangeDice(Coord(dir));
    }
}
