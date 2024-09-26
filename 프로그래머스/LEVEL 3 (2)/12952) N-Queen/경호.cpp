#include <math.h>
#include <vector>

using namespace std;

void n_queen(vector<int>& queen, int n, int count, int& answer)
{
    if(count == n)
    {
        ++answer;
        return;
    }
    
    for(int i = 0; i < n; ++i)
    {
        bool enable = true;
        for(int j = 0; j < count; ++j)
        {
            if(queen[j] == i || count - j == abs(i - queen[j]))
            {
                enable = false;
                break;
            }
        } 
        
        if(enable)
        {
            queen[count] = i;
            n_queen(queen, n, count + 1, answer);
            queen[count] = -1;
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    vector<int> queens(n, -1);
    n_queen(queens, n, 0, answer);
    
    return answer;
}