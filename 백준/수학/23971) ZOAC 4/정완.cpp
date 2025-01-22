/*
H: 행
W: 열
N: 행 간격
M: 열 간격
*/

#include <iostream>
typedef long long ll;

using namespace std;

ll solution(int H, int W, int N, int M)
{
    ll maxRow = (H + N) / (N + 1);  // 행 방향 참가자 수 올림 계산
    ll maxCol = (W + M) / (M + 1);  // 열 방향 참가자 수 올림 계산

    return maxRow * maxCol; // 총 참가자
}

int main(void)
{
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    cout << solution(H, W, N, M);
}