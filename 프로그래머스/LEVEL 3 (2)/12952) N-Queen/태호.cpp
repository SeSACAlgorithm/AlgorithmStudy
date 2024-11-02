#include <string>
#include <vector>

using namespace std;

int queen[15];

bool CanRowAttack(int prevRow, int curRow) { return prevRow == curRow; }
bool CanDiagonalAttack(int prevRow, int prevCol, int curRow, int curCol)
{
    return abs(prevRow - curRow) == abs(prevCol - curCol);
}

bool Find(int row, int col)
{
    for(int i = 0; i < col; ++i)
    {
        if(CanRowAttack(queen[i], row) || CanDiagonalAttack(queen[i], i, row, col))
            return false;
    }
    
    return true;
}

int BackTracking(int col, int n)
{
    if(col == n)
        return 1;
 
    int cnt = 0;
    
    for(int row = 0; row < n; ++row)
    {
        if(!Find(row, col)) continue;
        
        queen[col] = row;
        cnt += BackTracking(col + 1, n);
        queen[col] = -1;
    }
    
    return cnt;
}


int solution(int n) 
{  
    return BackTracking(0, n);
}
