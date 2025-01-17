#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n), answer(n, -1); // answer를 미리 -1로 초기화
    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 배열의 끝에서부터 탐색
    for (int i = n - 1; i >= 0; i--) {
        // 스택에 있는 값이 현재 값보다 작으면 제거
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // 스택이 비어 있지 않으면, top이 오큰수
        if (!s.empty()) {
            answer[i] = s.top();
        }

        // 현재 값을 스택에 추가
        s.push(arr[i]);
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
