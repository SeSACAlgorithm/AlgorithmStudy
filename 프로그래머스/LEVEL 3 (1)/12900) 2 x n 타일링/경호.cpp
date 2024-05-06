// 피보나치 수열의 규칙을 가지는데 그 이유를 모르겠음

#include <vector>

using namespace std;

int solution(int n) {
    vector<int> DP(n);
    DP[0] = 1, DP[1] = 2;
    for(int i = 2; i < n; ++i)
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000007;
    return DP.back();
}
