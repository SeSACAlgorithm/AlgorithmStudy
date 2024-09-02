#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string binary;  
    cin >> binary;

    // 이진수의 길이가 3의 배수가 아니면 앞에 0을 추가하여 3의 배수로
    int remain = binary.size() % 3;
    if (remain == 1) {
        binary = "00" + binary;
    } else if (remain == 2) {
        binary = "0" + binary;
    }

    // 3자리씩 잘라서 8진수로 변환
    for (int i = 0; i < binary.size(); i += 3) {
        // 각 3자리의 이진수를 8진수로 변환
        int octal = (binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 + (binary[i + 2] - '0');
        cout << octal;
    }

    cout << '\n'; 
    return 0;
}
