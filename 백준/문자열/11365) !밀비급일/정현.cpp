#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    
    while (true) { // 무한 반복 시작
        getline(cin, str); // 입력을 한 줄씩 받음

        if (str == "END") // 입력이 END면 프로그램 종료
            break;

        reverse(str.begin(), str.end()); // 문자열을 뒤집음
        cout << str << "\n";
    }
    
    return 0;
}
