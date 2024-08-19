#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[5];
    
    for(int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }

    int longlen = 0;
    for (int i = 0; i < 5; ++i) {
        if (arr[i].length() > longlen) {
            longlen = arr[i].length();
        }
    }

    for (int i = 0; i < longlen; ++i) {
        for (int j = 0; j < 5; ++j) {
            // 문자열의 길이를 넘어서는 경우는 출력하지 않음
            if (i < arr[j].length()) {
                cout << arr[j][i];
            }
        }
    }

    return 0;
}
