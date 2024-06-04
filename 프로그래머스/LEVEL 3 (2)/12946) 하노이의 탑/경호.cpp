#include <vector>
#include <math.h>

using namespace std;

void Hanoi(int n, int from, int to, vector<vector<int>>& answer, int& idx)
{
    if(n == 1)
    {
        answer[idx] = vector<int>{from, to};
        ++idx;
    }
    else
    {
        int other = 6 - from - to;
        
        Hanoi(n - 1, from, other, answer, idx);
        answer[idx++] = vector<int>{from, to};
        Hanoi(n - 1, other, to, answer, idx);
    }
}

vector<vector<int>> solution(int n) {
    int limit = static_cast<int>(pow(2, n) - 1);
    vector<vector<int>> answer(limit, vector<int>(2, 0));
    
    int idx = 0;
    Hanoi(n, 1, 3, answer, idx);
    
    return answer;
}