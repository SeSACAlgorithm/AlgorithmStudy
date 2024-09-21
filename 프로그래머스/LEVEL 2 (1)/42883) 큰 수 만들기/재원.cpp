#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    stack<char> s;
    
    // 각 자리 숫자를 처리
    for (int i = 0; i < number.size(); i++) {
        char current = number[i];
        
        // 스택이 비어있지 않고, 스택의 top이 현재 숫자보다 작으며, 제거할 수 있는 횟수(k)가 남아있을 경우
        while (!s.empty() && s.top() < current && k > 0) {
            s.pop(); // 스택에서 작은 숫자를 제거
            k--;     // 제거 횟수 감소
        }
        
        s.push(current);  // 현재 숫자를 스택에 추가
    }
    
    // 한바퀴 돌떄까지 만약 제거 횟수가 남아있다면, 뒤에서부터 남은 횟수만큼 제거
    while (k > 0) {
        s.pop();
        k--;
    }
    
    // 스택에 있는 숫자를 꺼내서 정답을 만든다
    string answer = "";
    while (!s.empty()) {
        answer = s.top() + answer;  // 스택은 LIFO 구조이므로, 역순으로 저장
        s.pop();
    }
    
    return answer;
}
