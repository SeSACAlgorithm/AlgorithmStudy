#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int limit = sqrt(n);
    for(int i = 1; i <= limit; i++)
        if(n % i == 0)
            answer += i + (n / i);
    
    return pow(limit, 2) == n ? answer - limit : answer;
}