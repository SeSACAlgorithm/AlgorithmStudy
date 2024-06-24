#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        // 공백인 경우 그대로 추가
        if (c == ' ') {
            answer += c;
        }
        // 대문자인 경우
        else if (c >= 'A' && c <= 'Z') {
            // 'Z'를 넘어가는 경우 A로 가게
            if (c + n > 'Z') {
                answer += c + n - 26;
            }
            else {
                answer += c + n;
            }
        }
        // 소문자인 경우
        else if (c >= 'a' && c <= 'z') {
            // 'z'를 넘어가는 경우 a로 넘어가게
            if (c + n > 'z') {
                answer += c + n - 26;
            }
            else {
                answer += c + n;
            }
        }
    }
    return answer;
}
