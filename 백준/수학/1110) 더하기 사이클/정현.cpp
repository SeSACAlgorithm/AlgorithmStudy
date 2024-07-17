#include <iostream>
using namespace std;

int main() {
    int num;            
    cin >> num;

    int original = num; // 최초 입력 숫자를 저장
    int count = 0;

    while (true) {
        int tens = num / 10;   // 앞자리
        int ones = num % 10;   // 뒷자리

        int sum = tens + ones; // 앞자리와 뒷자리 합

        // 새로운 숫자 -> 뒷자리 * 10 + 합의 뒷자리
        num = (ones * 10) + (sum % 10);
        count++;

        if (num == original)   // 새로 생성된 숫자가 최초 입력 숫자와 동일하면 종료
            break;
    }

    cout << count;
    return 0;
}
