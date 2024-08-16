#include <string>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string trit_string = "";  // ternary -> trit_string으로 변경

    // 10진수를 3진수로 변환
    while (n > 0) {
        trit_string += to_string(n % 3);
        n /= 3;
    }

    // 3진수를 10진수로 변환
    int power = 1;
    for (int i = trit_string.size() - 1; i >= 0; --i) {
        answer += (trit_string[i] - '0') * power;
        power *= 3;
    }

    return answer;
}
