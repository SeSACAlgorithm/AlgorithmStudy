#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i <= n; i++)
    {
        int limit = sqrt(i);
        bool isPrime = true;
        for(int j = 2; j <= limit; j++)
        {
            if(i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) answer++;
    }
    return answer;
}