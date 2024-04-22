#include <string>
#include <vector>

using namespace std;

unsigned long long dp[2002];


long long solution(int n) {
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    
    for(int i = 3; i < 2001; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    
    return dp[n];
}
