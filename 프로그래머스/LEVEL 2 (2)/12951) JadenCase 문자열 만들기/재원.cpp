#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int convert=0;
    int up=0;
    for(int i=0;i<s.length();i++)
    {
        if(i==0)
        {
            s[i]=toupper(s[i]);
            convert=1;
            continue;
        }
        
        if(isdigit(s[i]))
        {
            convert=1;
            up=0;
        }
        else if(s[i]==' ')
        {
            convert=0;
            up=1;
        }
        else
        {
            if(convert==1)
            {
                s[i]=tolower(s[i]);
            }
            if(up==1)
            {
                s[i]=toupper(s[i]);
                up=0;
                convert=1;
            }

        }
    }
    answer=s;
    return answer;
}
