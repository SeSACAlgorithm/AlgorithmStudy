#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    // 프로세스 대기열과 우선순위 큐 초기화
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});//원래큐의 정보와 현재 검사 인덱스 정보가 담길 큐 
        pq.push(priorities[i]);  //가장 큰 수가 제일 위에 오는 우선순위 큐 
    }

    int order = 0;

    // 대기열이 빌 때까지 반복
    while (!q.empty()) {
        int cur_priority = q.front().first; //원래 큐정보와
        int cur_index = q.front().second; //인덱스 위치 저장 
        q.pop();

        // 현재 프로세스가 가장 높은 우선순위인지 확인
        if (cur_priority == pq.top()) {
            pq.pop();
            order++;
            // 현재 프로세스가 우리가 찾는 프로세스인지 확인
            if (cur_index == location) {
                return order;
            }
        } else {
            // 우선순위가 높지 않으면 다시 큐의 뒤로 이동
            q.push({cur_priority, cur_index});
        }
    }

    return -1;  // 여기까지 올 일은 없지만 안전을 위해 추가
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;
    
    int result = solution(priorities, location);
    cout << "Target process is executed at order: " << result << endl;

    return 0;
}
