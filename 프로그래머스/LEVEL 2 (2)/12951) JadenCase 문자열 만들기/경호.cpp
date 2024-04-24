#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool is_first = true;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            is_first = true;
            continue;
        }
        
        if(is_first)
        {
            if(islower(s[i]))
                s[i] = toupper(s[i]);
                
            is_first = false;
            continue;
        }
        else
        {
            if(isupper(s[i]))
                s[i] = tolower(s[i]);
        }
    }
    
    return s;
}