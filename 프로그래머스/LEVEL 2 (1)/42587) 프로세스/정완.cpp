#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int ans = 0;
    int cnt = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i=0; i<priorities.size(); i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty())
    {
        int index = q.front().first;            // 문서 인덱스
        int value = q.front().second;           // 문서 우선순위
        q.pop();
        
        if(pq.top() == value)                   // 1. 우선 순위 같으면
        {
            pq.pop();                           // 가장 높은 우선순위 제거
            cnt++;                              // 실행된 문서 개수 증가
            
            if(index == location)               // 인덱스랑 위치랑 같으면
            {
                ans = cnt;
                break;
            }
        }
        
        else                                    // 2. 우선 순위 다르면
            q.push(make_pair(index, value));    // 문서를 큐의 맨 뒤로 이동
    }
    
    return ans;
}
