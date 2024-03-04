#include <string>

using namespace std;

string solution(string s) {
    int idx = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            idx = 0;
            continue;
        }
        
        s[i] = (idx & 1) == 0 ? toupper(s[i]) : tolower(s[i]);
        idx++;
    }
    return s;
}