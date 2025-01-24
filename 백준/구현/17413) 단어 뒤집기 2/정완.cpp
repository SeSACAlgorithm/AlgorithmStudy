#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    getline(cin, s);    // 공백을 포함한 문자열을 입력받아 변수 s에 저장

    stack<char> stk;

    for(int i=0; i<s.size(); i++)
    {
        // 태그 시작
        if(s[i] == '<')
        {
            // 현재 스택에 남아 있는 단어를 뒤집어서 출력
            while(!stk.empty())
            {
                cout << stk.top();  // 스택의 맨 위 문자 출력
                stk.pop();          // 출력 후 제거
            }

            while (s[i] != '>')
            {
                cout << s[i];       // 태그 문자 출력
                i++;                // 다음 문자
            }
            
            cout << ">";            // 태그 끝

            continue;               // 다음 반복문 실행
        }

        // 공백이 아닌 경우
        if(s[i] != ' ')
            stk.push(s[i]);

        // 공백이거나 문자열의 끝인 경우
        if(s[i] == ' ' || i == s.size() - 1)
        {
            while (!stk.empty())
            {
                cout << stk.top();  // 스택의 맨 위 문자 출력
                stk.pop();          // 출력 후 제거
            }
            
            if (s[i] == ' ')
                cout << " ";
        }
    }

    return 0;
}
