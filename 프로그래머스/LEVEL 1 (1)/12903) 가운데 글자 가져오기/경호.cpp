#include <string>

using namespace std;

string solution(string s) {
    int len = s.size();
    int half = len / 2;
    return (len & 1) == 1 ? s.substr(half, 1) : s.substr(half - 1, 2) ;
}