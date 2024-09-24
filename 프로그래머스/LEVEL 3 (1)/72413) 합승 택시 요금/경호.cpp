#include <vector>
#include <limits>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {  
    // 모든 지점간의 최소 거리를 저장할 벡터 선언
    // 자기 자신과의 거리는 0으로 초기화
    vector<vector<int>> costs(n + 1, vector<int>(n + 1, 1000001));
    for(int i = 0; i <= n; ++i)
        costs[i][i] = 0;
    // 요금 정보 적용
    for(const vector<int>& f: fares)
    {
        costs[f[0]][f[1]] = f[2];
        costs[f[1]][f[0]] = f[2];
    }
    
    // 플로이드 워셜 수행
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
    
    // 합승 요금 = 시작 지점부터 해당 위치까지의 요금 + A의 집까지의 요금 + B의 집까지의 요금
    // 가장 작은 값을 반환
    int answer = numeric_limits<int>::max();
    for(int i = 1; i <= n; ++i)
        answer = min(answer, costs[i][s] + costs[i][a] + costs[i][b]);
    
    return answer;
}