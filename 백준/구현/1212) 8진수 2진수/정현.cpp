#include <iostream>
#include <string>

using namespace std;

// 8진수 0~7을 2진수 3자리
string binary[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main() {
    string octal;  
    cin >> octal; 

    // 첫 번째 8진수 자리에 대한 처리 불필요한 앞자리 0 제거
    int first_digit = octal[0] - '0';  // 첫 번째 자리의 숫자 값
    cout << stoi(binary[first_digit]); // 앞자리 0을 제거한 2진수

    // 나머지 자리 처리 그대로 3자리씩
    for (int i = 1; i < octal.length(); i++) {
        int digit = octal[i] - '0';  // 각 자리 숫자 값
        cout << binary[digit];       // 대응하는 2진수
    }

    return 0;
}
