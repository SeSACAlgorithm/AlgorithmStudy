#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max_diff = 0;  // 최대 높이 차이
    int start = 0;     // 오르막길의 시작점
    int prev = 0;      // 이전 높이

    cin >> prev; 
    start = prev; // 첫 번째 높이를 오르막길의 시작점으로 설정

    // 두 번째 높이부터 마지막 높이까지 순차적으로 입력
    for (int i = 1; i < n; i++) {
        int curr;
        cin >> curr;

        if (curr > prev) {
            // 현재 높이가 이전 높이보다 크다면, 오르막길이 계속되는 상황
            // 현재 오르막길에서의 최대 높이 차이를 계산하고 업데이트
            max_diff = max(max_diff, curr - start);
        } else {
            // 현재 높이가 이전 높이보다 작다면, 오르막길이 끝난 상황
            // 새롭게 시작하는 오르막길의 시작점을 현재 높이로 설정
            start = curr;
        }

        prev = curr;
    }

    cout << max_diff << '\n'; 
    return 0;
}
