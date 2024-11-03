#include <string>
#include <vector>

using namespace std;


bool solve(int mid, const vector<int> stones, int k)
{
    int cnt = 0;
    
    for(int i = 0; i < stones.size(); ++i)
    {
        // 0보다 작거나 같다면 ++해주기
        // 돌 - mid 0이 아니라면 cnt 초기화
        
        stones[i] - mid > 0 ? cnt = 0 : ++cnt;            
        
        if(cnt == k)
            return false;
    }
    
    return true;
}

int solution(vector<int> stones, int k) 
{
    int answer = 0;
    
    int lo = 0, hi = 200000000;
    
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        
        if(solve(mid, stones, k)) lo = mid + 1;
        else hi = mid - 1;
    }
    
    return lo;
}
