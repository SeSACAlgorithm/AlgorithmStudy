#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    
    int all = brown + yellow;
    int limit = sqrt(all);
    
    int x = 0, y = 0;
    int curBrown = 0, curYellow = 0;
    for(int i = 1; i <= limit; i++)
    {
        if(all % i != 0) continue;
        
        x = all / i;
        y = i;
        curBrown = 2 * x + 2 * y - 4;
        if(curBrown != brown) continue;
        
        curYellow = all - curBrown;
        if(curYellow != yellow) continue;
        
        answer[0] = x;
        answer[1] = y;
        break;
    }
    
    return answer;
}