#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int P = 0;
    int Y = 0;
    for (int i = 0; i <= s.size(); i++) {
        //string�� i��°�� pȤ�� P�̸� p++
        if (s[i] == 'p' || s[i] == 'P') {
            P++;
        }
        //string�� i��°�� yȤ�� Y�̸� y++
        if (s[i] == 'y' || s[i] == 'Y') {
            Y++;
        }
    }
    //p��y�� �ٸ��ٸ� false
    if (P != Y) {
        answer = false;
    }

    return answer;
}