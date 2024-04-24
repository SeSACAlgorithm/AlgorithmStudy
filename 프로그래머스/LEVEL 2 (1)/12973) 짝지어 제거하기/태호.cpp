#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> szStack;

    
    for(int i = 0 ; i < s.size(); ++i)
    {
        if(szStack.empty() || szStack.top() != s[i]) szStack.push(s[i]);
        else if(szStack.top() == s[i]) szStack.pop();
    }
    
    if(szStack.empty()) return 1;

    return 0;
}
