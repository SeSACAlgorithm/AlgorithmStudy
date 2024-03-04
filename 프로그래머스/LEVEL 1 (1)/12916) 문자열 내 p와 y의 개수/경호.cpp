#include <string>

using namespace std;

bool solution(string s)
{
    int pCnt = 0, yCnt = 0;
    for(char c : s)
    {
        if(c == 'P' || c == 'p')
            pCnt++;
        else if(c == 'Y' || c == 'y')
            yCnt++;
    }
    
    return pCnt == yCnt;
}