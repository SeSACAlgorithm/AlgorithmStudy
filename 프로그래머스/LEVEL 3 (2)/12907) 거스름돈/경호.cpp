#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<int> DP(n + 1, 0);
    DP[0] = 1; // DP[i - m]을 1로 만들기 위해 1로 초기화

    // n원을 만들 수 있는 경우의 수
    // = (n - money[0]원을 만들 수 있는 경우의 수) + (n - money[1]원을 만들 수 있는 경우의 수) + ...
    // 따라서 DP[i]에 DP[i - m]값을 중첩
    for(const int& m : money)
        for(int i = m; i <= n; ++i)
            DP[i] = (DP[i] + DP[i - m]) % 1000000007;

    return DP[n] ;
}