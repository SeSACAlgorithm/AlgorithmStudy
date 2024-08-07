#include <iostream>
using namespace std;

// 피보나치 수를 계산하는 함수
long long fibonacci(int n) {
    // 만약 n이 0이라면, 0을 반환 (첫 번째 피보나치 수)
    if (n == 0) return 0;
    // 만약 n이 1이라면, 1을 반환 (두 번째 피보나치 수)
    if (n == 1) return 1;

    // 두 개의 숫자를 준비, 처음 두 피보나치 수 0과 1
    long long f1 = 0, f2 = 1, f3;

    // 두 번째 숫자부터 n번째 숫자까지 피보나치 수 계산
    for (int i = 2; i <= n; i++) {
        // 다음 피보나치 수는 이전 두 수의 합
        f3 = f1 + f2;
        // 이제 f1은 다음 단계로 가기 위해 f2가 되고,
        f1 = f2;
        // f2는 방금 계산한 피보나치 수가 됨
        f2 = f3;
    }

    // n번째 피보나치 수를 반환
    return f3;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);

    return 0;
}
