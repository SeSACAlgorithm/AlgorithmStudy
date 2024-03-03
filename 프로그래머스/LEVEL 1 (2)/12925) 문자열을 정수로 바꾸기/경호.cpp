#include <string>

using namespace std;

int solution(string s) {
    bool plus = s[0] == '+';
    bool minus = s[0] == '-';
    int answer = plus || minus ? stoi(s.substr(1, s.size() - 1)) : stoi(s);
    return minus ? -answer : answer;
}