#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    //짝수일 경우 가운데 두글자
    //홀수일 경우 가운데 한글자 <- 이건 짝수든 홀수든 무조건 추가해야함
    // 짝수일 경우
    if (s.size() % 2 == 0)
    {
        // 가운데 첫번째 글자
        answer += s[s.size() / 2 - 1];
    }
    // 가운데 글자
    answer += s[s.size() / 2];
    return answer;
}
