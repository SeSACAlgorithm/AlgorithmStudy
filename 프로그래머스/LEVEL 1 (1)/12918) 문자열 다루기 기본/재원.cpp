#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    // 1. 길이 체크
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }

    // 2. 각 문자가 숫자인지 확인
    for (char c : s) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    
    // 모든 조건을 만족하면 true
    return true;
}
