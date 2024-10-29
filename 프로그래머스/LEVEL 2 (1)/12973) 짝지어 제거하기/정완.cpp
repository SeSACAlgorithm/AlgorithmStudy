#include <iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string s)
{
    stack<char> s_string;
    
    for(int i=0; i<s.size(); i++)
    {
        if(!s_string.empty() && s_string.top() == s[i])
            s_string.pop();
        
        else
            s_string.push(s[i]);
    }
    
    return s_string.empty() ? 1 : 0;
}
