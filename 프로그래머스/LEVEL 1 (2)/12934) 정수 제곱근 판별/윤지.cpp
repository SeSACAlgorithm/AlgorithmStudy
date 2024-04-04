#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    bool flag = 0;
    long long tmp = 0;
    
    for(long long i = 1; i <= n; i++){
        if(i * i == n){
            flag = true;
            tmp = i;
            break;
        }
    }
    
    if(flag){
        answer = (tmp + 1) * (tmp + 1);
    } else {
      answer = -1;  
    }
    
    return answer;
}
