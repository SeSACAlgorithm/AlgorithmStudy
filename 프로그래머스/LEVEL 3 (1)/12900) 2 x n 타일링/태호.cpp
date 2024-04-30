#include <string>
#include <vector>

using namespace std;

int dp[60002];

int solution(int n) {
    int answer = 0;
    
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    
    for(int i = 3; i < 60001; ++i)
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    
    return dp[n];
}
