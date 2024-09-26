#include <string>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> s;
    int temp;
    
    // n이 0보다 클 때까지 나머지를 구하고 스택에 저장
    while(n > 0) {
        temp = n % 3;
        if (temp == 0) {
            temp = 4;  // 0일 경우 124나라의 규칙에 맞게 4로 변환
            n -= 1;    // n이 0일 경우 1을 빼주어야 함
        }
        s.push(temp);
        n /= 3;  // n을 3으로 나누어 반복 진행
    }
    
    // 스택에서 값을 꺼내어 결과 문자열로 변환
    while(!s.empty()) {
        answer += to_string(s.top());
        s.pop();
    }
    
    return answer;
}
