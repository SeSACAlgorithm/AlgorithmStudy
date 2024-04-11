#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long ans = 0;
    long long num = sqrt(n);
    
    ans = num * num == n ? pow(num+1, 2) : -1 ;
    
    return ans;
}
