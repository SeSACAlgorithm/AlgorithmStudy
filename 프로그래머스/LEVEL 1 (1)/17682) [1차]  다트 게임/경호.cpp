#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int bef = 0, cur = 0;
    int idx = 0;
    while(idx < dartResult.size())
    {
        // check num
        bool isTen = dartResult[idx + 1] == '0';
        cur = isTen ? 10 : dartResult[idx] - '0';
        char bonus = isTen ? dartResult[idx + 2] : dartResult[idx + 1];
        switch(bonus)
        {
            case 'D':
                cur = pow(cur, 2);
                break;
            case 'T':
                cur = pow(cur, 3);
                break;
        }
        
        // check option
        int optionIdx = isTen ? idx + 3 : idx + 2;
        if(optionIdx < dartResult.size())
        {
            if(dartResult[optionIdx] == '*')
            {
                cur *= 2;
                answer += bef;
                idx += optionIdx - idx + 1;
            }
            else if(dartResult[optionIdx] == '#')
            {
                cur *= -1;
                idx += optionIdx - idx + 1;
            }
            else
                idx += optionIdx - idx;
        } 
        else
            idx += optionIdx - idx;
        
        answer += cur;
        bef = cur;
    }
    return answer;
}