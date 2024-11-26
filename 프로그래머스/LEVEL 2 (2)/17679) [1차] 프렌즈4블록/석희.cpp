/*
    1. 4개 블록 찾기 (board에서) & 없애기 (copyBoard에서)
    2. 지워진 후에 위에 있는 블록 아래로 떨어지기 (resultBoard)
    3. 4X4가 없어질 때까지 반복
*/

#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> copyBoard;
bool findFour = false;

int FindRemoveBlock(int m, int n)
{
    int answer = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(copyBoard[i][j] == ' ') answer++;
        }
    }
    return answer;
}

void DropBlock(int m, int n)
{
    char resultBoard[30][30];
    memset(resultBoard, ' ', sizeof(resultBoard));

    for(int j = 0; j < n; j++)
    {
        int indexI = m-1;
        for(int i = m-1; i >= 0; i--)
        {
            if(copyBoard[i][j] != ' ')
            {
                resultBoard[indexI][j] = copyBoard[i][j];
                indexI--;
            }
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            copyBoard[i][j] = resultBoard[i][j];
        }
    }
}

void FindFourBlock(vector<string> board, int m, int n, int sx, int sy)
{
    char block = board[sx][sy];
    if(block != ' ' && board[sx+1][sy] == block && 
    board[sx+1][sy+1] == block && board[sx][sy+1] == block)
    {
        findFour = true;
        copyBoard[sx][sy] = ' ';
        copyBoard[sx+1][sy] = ' ';
        copyBoard[sx][sy+1] = ' ';
        copyBoard[sx+1][sy+1] = ' ';
    }
}

int solution(int m, int n, vector<string> board)
{
    copyBoard = board;
    while(true)
    {
        findFour = false;
        for(int i = 0; i < m-1; i++)
        {
            for(int j = 0; j < n-1; j++)
            {
                FindFourBlock(board, m, n, i, j);
            }
        }
        DropBlock(m, n);
        board = copyBoard;
        if(findFour == false) return FindRemoveBlock(m, n);
    }
    
    return 0;
}