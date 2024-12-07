#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]);
    
    while(!pq.empty())
    {
        int a = pq.top();
        pq.pop();
        
        if(a >= K)
            break;
        
        else
            if(pq.empty())
                return -1;
        
        int b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
        ans++;
    }
    
    return ans;
}
