#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int n : scoville)
        pq.push(n);
    
    int answer = 0;
    int back1 = 0, back2 = 0;
    while(pq.size() > 1)
    {
        if(pq.top() >= K)
            return answer;
        
        back1 = pq.top(); pq.pop();
        back2 = pq.top(); pq.pop();
        pq.push(back1 + back2 * 2);
        answer++;
    }
    
    return pq.top() >= K ? answer : -1;
}