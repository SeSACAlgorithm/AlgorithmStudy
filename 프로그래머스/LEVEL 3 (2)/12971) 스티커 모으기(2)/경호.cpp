#include <vector>
#include <math.h>

using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    if(n == 1) return sticker[0];
    if(n == 2) return max(sticker[0], sticker[1]);
    if(n == 3) return max(sticker[0] + sticker[2], sticker[1]);

    // 첫번째 스티커 포함
    vector<int> DP_A(n);
    DP_A[0] = sticker[0], DP_A[1] = DP_A[0];
    DP_A[2] = DP_A[0] + sticker[2];
    for(int i = 3; i < n - 1; ++i)
         DP_A[i] = max(DP_A[i - 1], sticker[i] + DP_A[i - 2]);
    DP_A[n - 1] = DP_A[n - 2];
    
    // 첫번째 스티커 미포함
    vector<int> DP_B(n);
    DP_B[0] = 0, DP_B[1] = sticker[1];
    DP_B[2] = max(sticker[2], DP_B[1]);
    for(int i = 3; i < n; ++i)
         DP_B[i] = max(DP_B[i - 1], sticker[i] + DP_B[i - 2]);

    return max(DP_A.back(), DP_B.back());
}