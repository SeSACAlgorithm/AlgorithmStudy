#include<string>
#include <iostream>
#include<stack>

using namespace std;

bool solution(string s)
{
    stack<char> st_char;
    
    for (int i = 0; i < s.length(); i++)
    {
        // 여는 괄호면
        if (s[i] == '(') st_char.push(s[i]);
        else if (s[i] == ')')
        {
            if (st_char.empty() || st_char.top() != '(') return false;
            else
            {
                st_char.pop();
            }
        }
    }

    if (!st_char.empty()) return false;
    return true;
}
