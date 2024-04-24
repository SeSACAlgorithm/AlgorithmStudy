#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> stackInt;

    
    for(char c : s)
    {
        if(c == '(') 
            stackInt.push('(');
        else 
        {
            if(!stackInt.empty())
            {
                stackInt.pop();
            }
            else
            {
                stackInt.push(')');
            }
        }   
    }
    
    if(stackInt.empty())
        return true;
    else
        return false;
}
