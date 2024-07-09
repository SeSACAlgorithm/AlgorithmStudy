#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> s_str;

    for (int i = 0; i < s.size(); i++)
    {
        if (!s_str.empty() && s_str.top() == s[i])
            s_str.pop();
        else
            s_str.push(s[i]);
    }

    return s_str.empty() ? 1 : 0;
}