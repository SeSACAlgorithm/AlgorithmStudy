#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < signs.size(); i++) {
        // singns[i]가 true 라면
        if (signs[i]) {
            // 그대로 더하기
            answer += absolutes[i];
        }
        // signs[i]가 false라면
        else {
            // 음수니까 빼자
            answer -= absolutes[i];
        }
    }

    return answer;
}