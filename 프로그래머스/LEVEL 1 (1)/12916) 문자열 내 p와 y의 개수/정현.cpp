#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int P = 0;
    int Y = 0;
    for (int i = 0; i <= s.size(); i++) {
        //string의 i번째가 p혹은 P이면 p++
        if (s[i] == 'p' || s[i] == 'P') {
            P++;
        }
        //string의 i번째가 y혹은 Y이면 y++
        if (s[i] == 'y' || s[i] == 'Y') {
            Y++;
        }
    }
    //p와y가 다르다면 false
    if (P != Y) {
        answer = false;
    }

    return answer;
}