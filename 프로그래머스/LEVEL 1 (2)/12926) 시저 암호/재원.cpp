#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (c >= 'a' && c <= 'z') { // c 가 소문자라면 
            // 이동 후 알파벳 범위를 초과하지 않도록 조정
            c = (c - 'a' + n) % 26 + 'a'; //26을 나눔으로서 순환하도록 
        } else if (c >= 'A' && c <= 'Z') {
            // 이동 후 알파벳 범위를 초과하지 않도록 조정
            c = (c - 'A' + n) % 26 + 'A';
        }
        // 공백은 그대로 추가
        answer += c;
    }
    
    return answer;
}
