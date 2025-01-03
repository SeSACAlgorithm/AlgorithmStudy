#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> tmp;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')                             // 열린 괄호
            tmp.push('(');
        
        else if(s[i] == ')')                        // 닫힌 괄호
        {
            if(tmp.empty() || tmp.top() != '(')
                return false;
            
            else
                tmp.pop();
        }
    }
    
    if(tmp.empty())
        return true;
    
    else
        return false;
}
