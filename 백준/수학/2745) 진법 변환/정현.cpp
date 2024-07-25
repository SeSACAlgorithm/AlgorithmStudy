#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    int b, result = 0, temp = 1;


    cin >> n >> b;

    // 문자열의 마지막 문자부터 첫 번째 문자까지 반복
    for (int i = n.size() - 1; i >= 0; --i) {
        // 문자가 숫자인지 문자인지에 따라 숫자 값을 계산
        int num = (n[i] >= '0' && n[i] <= '9') ? n[i] - '0' : n[i] - 'A' + 10;
        
        // 현재 자리의 숫자 값을 현재 진법의 제곱과 곱해서 결과에 더함
        result += num * temp;
        
        temp *= b;
    }
    
    cout << result << "\n";

    return 0;
}
