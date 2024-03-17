#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int tmp = 0;

    if (s.size() == 4 || s.size() == 6) {
        for (int i = 0; i < s.size(); i++) {
            tmp = s[i] - '0';

            if (tmp < 0 || tmp > 9) {
                answer = false;
                break;
            }
            else {
                answer = true;
            }
        }
    }
    else {
        answer = false;
    }


    return answer;
}