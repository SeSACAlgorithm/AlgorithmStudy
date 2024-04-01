#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int sum = 0;
    int diff = 0;
    int root = 0;
    for(int i = 1; i < n; i++)
    {
        sum += i;
        if(sum < n) continue;
        
        diff = (sum - n) * 2;
        // 근의 공식
        root = sqrt(1 + (4 * diff));
        if(pow(root, 2) != (1 + (4 * diff))) continue;
        if((root & 1) == 0) continue;
        
        answer++;
    }
    
    return answer;
}