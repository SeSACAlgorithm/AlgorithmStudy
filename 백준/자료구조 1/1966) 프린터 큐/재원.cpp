#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int times;
    cin >> times;

    while (times--) {
        int N, M;
        cin >> N >> M;  // N: 문서 개수, M: 우리가 궁금한 문서의 인덱스

        // 문서의 우선순위와 인덱스를 큐에 저장
        queue<pair<int, int>> q;
        priority_queue<int> max_priority; // 우선순위 큐 (최대값 우선)

        // 문서 우선순위 입력 받기
        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({priority, i});  // 우선순위와 문서 인덱스 저장
            max_priority.push(priority); // 최대 우선순위 찾기
        }

        int count = 0;  // 출력 순서
        while (!q.empty()) {
            int curr_priority = q.front().first; // 현재 문서의 우선순위
            int curr_index = q.front().second; // 현재 문서의 인덱스

            // 우선순위가 가장 높은 문서가 큐 앞에 오지 않으면 큐 뒤로 보냄
            if (curr_priority == max_priority.top()) {
                count++; // 출력 순서 증가
                if (curr_index == M) { // 우리가 궁금한 문서가 출력되면
                    cout << count << endl;
                    break;
                }
                q.pop();  // 출력된 문서 제거
                max_priority.pop();  // 우선순위 큐에서도 제거
            } else {
                q.push(q.front()); // 큐의 앞에 있는 문서를 뒤로 보냄
                q.pop();
            }
        }
    }

    return 0;
}
