#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2, 11, 14, 17, 21
// n개 == 2개를 제거했을 때 각 바위 거리의 최솟값을 구해야함.
// 미리 최솟값을 구해놓고 하는게 베스트일듯?
// 바위는 n 개 == 2개 지울 수 있다.
// 위에서 구한 거리의 최솟값 중에 가장 큰 값은 4입니다.
// for 문 돌려서 mid 값보다 거리값이 큰 것만 ++ 하자
// 일단 정렬하고 이분 탐색을 수행하자.

bool solve(int mid, const vector<int>& rocks, int n, int distance)
{
    int pre = 0;
    int cnt = 0;
    
    for(int i = 0; i < rocks.size(); ++i)
    {
        if(rocks[i] - pre < mid)
            ++cnt;
        else
            pre = rocks[i];
    }
    
    if(distance - pre < mid)
        ++cnt;
    
    cout << cnt << ' ';
    
    return cnt <= n;
}


int solution(int distance, vector<int> rocks, int n) 
{
    sort(rocks.begin(), rocks.end()); 

    int lo = 0, hi = distance; 
    int answer = 0;

    while (lo <= hi) 
    {
        int mid = (lo + hi) / 2; 

        if (solve(mid, rocks, n, distance)) 
        {
            lo = mid + 1; 
        }
        else 
        {
            hi = mid - 1; 
        }
    }

    return hi; 
        
}
