#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;

    for (int i = 0; i < s.size(); i++) 
    {
        if (s[i] == ' ')  // 공백이라면 index -1로 초기화
        {   
            index = -1;
        }
        else 
        {
            if (index % 2 == 0)  // 인덱스를 기준으로 짝수부분 대문자로
            {    
                s[i] = toupper(s[i]); 
            }
            else 
            {                 
                s[i] = tolower(s[i]);
            }
        }
        index++;  
    }

    answer = s;

    return answer;
}
