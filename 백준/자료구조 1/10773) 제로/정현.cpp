#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;  
    cin >> k;

    stack<int> s;  // 숫자를 저장할 스택
    int sum = 0;   

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;

        if (x == 0) {
            // x가 0이면, 스택에서 숫자 하나를 제거하고 그 값을 합계에서 뺀다
            if (!s.empty()) {
                sum -= s.top();
                s.pop();
            }
        } else {
            // x가 0이 아니면, 스택에 숫자를 추가하고 그 값을 합계에 더한다
            s.push(x);
            sum += x;
        }
    }

    cout << sum << endl;

    return 0;
}
