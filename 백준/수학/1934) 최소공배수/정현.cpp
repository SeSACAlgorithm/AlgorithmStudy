#include <iostream>

using namespace std;

// 최대공약수를 구하는 함수 (유클리드 호제법 사용)
int GCD(int a, int b) {
    if (b == 0) // b가 0이면 a가 최대공약수
        return a;
    return GCD(b, a % b); // 재귀 호출을 통해 최대공약수를 찾음
}

int main() {

    ios::sync_with_stdio(false); // 입출력 속도를 빠르게 하기 위해
    cout.tie(0); // cout의 tie를 해제하여 성능을 최적화
    cin.tie(0); // cin의 tie를 해제하여 성능을 최적화

    int T, num1, num2;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> num1 >> num2;

        int gcd = GCD(num1, num2); // 최대공약수 계산
        int lcm = (num1 * num2) / gcd; // 최소공배수 계산

        cout << lcm << "\n";
    }

    return 0;
}
