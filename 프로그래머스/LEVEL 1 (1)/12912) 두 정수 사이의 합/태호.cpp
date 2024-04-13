#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

long long solution(int a, int b) {
    if(a == b)
        return a;
    
    int iDiff = abs(a - b) - 1;
    int iSmall = a + 1;
    
    if(a > b)
        iSmall = b + 1;
    
    
    long long answer = 0;
    
    for(int i = 0; i < iDiff; ++i)
    {
        answer += iSmall + i;
    }
    
    return answer + a + b;
}
