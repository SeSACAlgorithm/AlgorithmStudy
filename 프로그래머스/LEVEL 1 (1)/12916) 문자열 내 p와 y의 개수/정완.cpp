#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool ans = true;
    int pP=0;
    int yY=0;
    for(int i=0; i<s.size();i++)
    {
        if(s[i] == 'p' || s[i] == 'P')
        {
            pP +=1;
        }
        if(s[i] == 'y' || s[i] == 'Y')
        {
            yY +=1;
        }
    }
    
    if(pP != yY)
    {
        ans = false;
    }

    return ans;
}
