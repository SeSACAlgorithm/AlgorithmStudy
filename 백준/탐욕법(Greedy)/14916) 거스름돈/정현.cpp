#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 1 또는 3은 5와 2로 거슬러 줄 수 없으므로 -1 
    if (n == 1 || n == 3) {
        cout << -1;
        return 0;
    }

    // 먼저 5원짜리 동전을 최대한 많이 사용
    int five = n / 5;  // 5원짜리 동전의 개수
    int remain = n % 5;  // 5로 나눈 나머지

    // 나머지가 2원으로 나누어질 때까지 5원짜리 동전의 개수를 줄이면서 확인
    while (five >= 0) {
        if (remain % 2 == 0) {  // 나머지가 2로 나누어지면
            cout << five + remain / 2;  // 5원과 2원의 합을 출력
            return 0;
        }
        five--;  // 5원짜리 동전의 개수를 줄이고
        remain += 5;  // 그만큼 나머지를 5 더해 다시 계산
    }

    // 2원과 5원으로 나누어떨어지지 않는 경우
    cout << -1;
    return 0;
}
