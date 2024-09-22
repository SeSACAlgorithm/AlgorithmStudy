#include <iostream>
#include<string>
#include<stack>
using namespace std;

//스택 사용
//순서대로 쌓다가 겹치는게있으면 기존꺼 넣는거 삭제
//합치기 
//스택에 모든 값을 다 넣었는데 스택에 알파벳이 남아있으면 0리턴

int solution(string s)
{
    int answer = 0;
    stack <char> st;
    

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty()&&st.top()==s[i])
            {
                st.pop();//스텍에서 겹친부분 빼기
            }
            else
            {
                st.push(s[i]); //스택에 넣기
            }
            
        }
        
        if(st.empty())
            answer=1;
  
    

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
