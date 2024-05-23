#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> DP(n);
    DP[0] = 1, DP[1] = 2;
    for(int i = 2; i < n; ++i)
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1234567;
    
    return DP.back();
}