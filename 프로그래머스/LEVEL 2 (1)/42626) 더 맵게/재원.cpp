#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());  // 최소 힙 생성
    int mixCount = 0;

    while (pq.top() < K) {  // 가장 작은 값이 K 이상이 될 때까지 반복
        if (pq.size() < 2)  // 더 이상 섞을 수 없는 경우
            return -1;

        int first = pq.top();  // 가장 작은 값
        pq.pop();
        int second = pq.top();  // 두 번째로 작은 값
        pq.pop();

        int newScoville = first + (second * 2);  // 새로운 스코빌 지수 계산
        pq.push(newScoville);  // 힙에 다시 넣기
        mixCount++;
    }

    return mixCount;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(scoville, K) << endl;  // 출력: 2

    return 0;
}
