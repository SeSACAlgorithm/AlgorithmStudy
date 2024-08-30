#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N; 
    cin >> N;

    stack<int> s; 

    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;

        // push 스택에 값을 추가
        if (command == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        // pop 스택의 가장 위에 있는 값을 제거하고 출력
        // 스택이 비어 있으면 -1을 출력
        else if (command == "pop") {
            if (s.empty()) {
                cout << -1 << endl;
            } else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        // size 스택에 들어있는 정수의 개수를 출력
        else if (command == "size") {
            cout << s.size() << endl;
        }
        // empty 스택이 비어 있으면 1 아니면 0 출력
        else if (command == "empty") {
            cout << (s.empty() ? 1 : 0) << endl;
        }
        // top 스택의 가장 위에 있는 값을 출력
        // 스택이 비어 있으면 -1을 출력
        else if (command == "top") {
            if (s.empty()) {
                cout << -1 << endl;
            } else {
                cout << s.top() << endl;
            }
        }
    }

    return 0;
}
