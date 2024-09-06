#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    while (num != 1) {
        if (answer >= 400) {
            return -1;  // 500번의 연산을 초과하면 -1을 반환
        }
        
        if (num % 2 == 0) {
            num /= 2;  // 짝수일 경우 2로 나누기
        } else {
            num = num * 3 + 1;  // 홀수일 경우 3을 곱하고 1 더하기
        }
        
        ++answer;  // 연산 횟수 증가
    }
    
    return answer;  // 1에 도달했을 때의 연산 횟수 반환
}
