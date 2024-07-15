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
    int min, max;
    cin >> min >> max;

    int result = 0; // 소수의 합
    int minNumber = -1; // 최솟값 소수 -1로 설정
    bool firstPrimeFound = false; // 첫 번째 소수 발견 여부

    for (int i = min; i <= max; i++) {
        if (isPrime(i)) {
            result += i;
            if (!firstPrimeFound) {
                minNumber = i;
                firstPrimeFound = true;
            }
        }
    }

    if (minNumber == -1) {
        cout << -1 << endl; // 소수가 없을 경우 -1 출력
    } else {
        cout << result << endl << minNumber << endl; // 소수의 합과 최솟값 소수 출력
    }

    return 0;
}
