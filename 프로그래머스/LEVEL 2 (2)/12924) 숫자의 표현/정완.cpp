#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    for(int i=1; i<n; i++)
    {
        int sum = 0, begin = i;
        
        while(sum < n)
        {
            sum += begin;
            begin++;            // 연속된 다음 수
        }
        
        if(sum == n)
            ans++;              // 카운트
    }
    return ans + 1;             // n = n 성립 함으로 1 더해줌
}
