#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    // 처음 이동할 때는 무조건 (현재위치) + 1 이어야함 (그래야 순간이동 가능)
    int curLoc = 1;
    int energy = 1;  // 이때 처음 움직이면 에너지도 자동으로 + 1이 됨
    
    while(curLoc != n){
        if( 2*curLoc < n ){
            //순간이동 할 경우, 목표 지점보다 작을 때 목표지점을 반으로 줄임
            if(n % 2 == 0){
                n = n / 2;
            } else {
                //반으로 나눴을때 홀수면, +1 칸 무조껀 가야함으로 에너지 +1
                n = (n-1) / 2;
                energy += 1;
            }
        // 현재 위치 * 2 가 목표 지점보다 크거나 같으면 현재 위치 +1 하고 다시 비교
        } else {
            curLoc += 1;
        }
    }
    
    ans = energy;
    
    return ans;
}
