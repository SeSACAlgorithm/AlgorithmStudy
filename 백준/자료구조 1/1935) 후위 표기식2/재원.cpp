#include <iostream>
#include <stack>
#include <iomanip>  // 출력 형식 설정을 위한 헤더
using namespace std;

int main() {
    int count;
    cin >> count;

    string inputs;
    cin >> inputs;

    int arr[26];  // A-Z에 대한 값 배열
    stack<double> s;

    // 알파벳에 해당하는 값 입력 받기
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }

    // 후위표기식 계산
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] >= 'A' && inputs[i] <= 'Z') {  // 알파벳이라면
            s.push(arr[inputs[i] - 'A']);  // A=0, B=1, ..., Z=25
        } else {  // 연산자라면
            double temp = s.top();
            s.pop();
            double result;

            switch (inputs[i]) {
                case '*':
                    result = s.top() * temp;
                    s.pop();
                    break;
                case '/':
                    result = s.top() / temp;
                    s.pop();
                    break;
                case '+':
                    result = s.top() + temp;
                    s.pop();
                    break;
                case '-':
                    result = s.top() - temp;
                    s.pop();
                    break;
            }

            s.push(result);  // 계산된 결과를 다시 스택에 넣기
        }
    }

    // 최종 결과는 스택에 하나만 남아있어야 함
    double final_result = s.top();
    cout << fixed << setprecision(2) << final_result;  // 소수점 2자리까지 출력
    return 0;
}
