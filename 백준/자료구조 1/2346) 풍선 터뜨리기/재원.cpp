#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int count;
    cin >> count;

    vector<int> v(count + 1); // 1부터 count까지 사용
    for (int i = 1; i <= count; i++) {
        cin >> v[i];
    }

    deque<int> dq; // 인덱스를 관리할 deque
    for (int i = 1; i <= count; i++) {
        dq.push_back(i);
    }

    int index = 0; // 처음 터트릴 풍선 인덱스
    while (!dq.empty()) {
        // 현재 인덱스 출력
        index = dq.front();
        cout << index << " ";
        
        dq.pop_front(); // 현재 풍선 터트리기

        // 다음 인덱스 계산
        if (v[index] > 0) {
            // 양수일 경우
            for (int steps = v[index] - 1; steps > 0; steps--) {
                dq.push_back(dq.front()); // 끝으로 이동
                dq.pop_front();
            }
        } else {
            // 음수일 경우
            for (int steps = -v[index]; steps > 0; steps--) {
                dq.push_front(dq.back()); // 시작으로 이동
                dq.pop_back();
            }
        }
    }

    return 0;
}
