#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    string ans= "";
    sort(s.begin(), s.end(), greater<int>());
    ans = s;
    
    return s;
}
