#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    // 문자열의 길이가 4혹은 6이 아니면 false
    if (s.size() != 4 && s.size() != 6)
        answer = false;
    // 문자열이 숫자로만 구성되어 있지 않다면 false
    // 아스키코드로 0~9 가 0~9!!
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            answer = false;
    }
    return answer;
}