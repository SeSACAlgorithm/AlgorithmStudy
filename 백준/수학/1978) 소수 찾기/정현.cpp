#include <iostream>
using namespace std;

// 소수 판별 함수
bool isPrime(int num) {
    if (num <= 1) return false; // 1 이하의 수는 소수가 아님
    if (num == 2) return true; // 2는 소수
    if (num % 2 == 0) return false; // 짝수는 소수가 아님
    for (int i = 3; i * i <= num; i += 2) { // 제곱근까지만 검사
        if (num % i == 0) return false;
    }
    return true; // 나누어떨어지는 수가 없으면 소수
}

int main() {
    int N; // 수의 개수
    cin >> N;

    int A; // 입력값
    int cnt = 0; // 소수의 개수

    while (N--) {
        cin >> A;
        if (isPrime(A)) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
