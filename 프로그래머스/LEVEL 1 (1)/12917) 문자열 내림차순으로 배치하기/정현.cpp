#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    // 내림차순 정렬
    // 1. reverse 반복자인 rbegin, rend 이용
    sort(s.rbegin(), s.rend());
    return s;
}
