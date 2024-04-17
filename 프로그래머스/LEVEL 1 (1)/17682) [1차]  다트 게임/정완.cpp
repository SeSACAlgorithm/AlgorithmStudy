#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int ans = 0;
    int i = 0;
    vector<int> score;
    int sqr;
    
    while(i<dartResult.size())
    {
        if(isdigit(dartResult[i]))
        {
            if(isdigit(dartResult[i+1]))            // 두 자리수인가?
            {
                score.push_back(stoi(dartResult.substr(i,2)));
                i += 2;
            }
            
            else                                    // 한 자리수이면 문자를 숫자로 ASCII
            {
                score.push_back(dartResult[i] - '0');
                i++;
            }
        }
        
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            sqr = (dartResult[i] == 'S') ? 1 : (dartResult[i] == 'D') ? 2 : 3;
            score.back() = pow(score.back(), sqr);
            i++;
        }
        
        else if(dartResult[i] == '*' || dartResult[i] == '#')
        {
            if(dartResult[i] == '*')
            {
                score.back() *= 2;
                
                if(score.size()>1)
                    score[score.size()-2] *= 2;
                i++;
            }
            
            else
            {
                score.back() *= -1;
                i++;
            }
        }
    }
    
    for(int a : score)
        ans += a;
    
    return ans;
}
