#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    // �������� ����
    // 1. reverse �ݺ����� rbegin, rend �̿�
    sort(s.rbegin(), s.rend());
    return s;
}
