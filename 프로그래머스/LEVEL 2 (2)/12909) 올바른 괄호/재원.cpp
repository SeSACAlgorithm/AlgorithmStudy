#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <char> st;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
            s[i]=' ';
        }
        else
        {
            if(!st.empty())
            {
                st.pop();
                s[i]=' ';
            }
        }

    }
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ')
        {
            answer=false;
            break;
        }
    }
        if(!st.empty())
        {
            answer=false;
        }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
