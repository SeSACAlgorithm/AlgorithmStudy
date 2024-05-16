#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    bool temp[1000000] = { 0 };  // 1000000 크기의 배열을 false
    for (int i = 2; i <= n; i++) {  // 2부터 n까지 반복
        if (temp[i])  // 만약 temp[i]가 true이면 이미 소수가 아님
            continue;  // 다음 숫자로 건너뜀
        answer++;  // 소수 개수 증가
        for (int j = i; j <= n; j += i) {  // i의 배수를 모두 true로 설정
            temp[j] = true;  // i의 배수는 소수가 아님
        }
    }
    return answer;  // 소수의 개수 반환
}