#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string ans = "";
    
    ans += toupper(s[0]);
    
    for(int i=1; i<s.size(); i++)
    {
        if(s[i-1] == ' ')
            ans += toupper(s[i]);
        else
            ans += tolower(s[i]);
    }
    return ans;
}
