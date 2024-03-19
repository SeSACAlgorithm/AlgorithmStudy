#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans = 0;
    
    bool p = s[0] == '+';
    bool m = s[0] == '-';
    
    ans = m || p ? stoi(s.substr( 1, s.size()-1)) : stoi(s);
    
    return m ? -ans : ans;
}
