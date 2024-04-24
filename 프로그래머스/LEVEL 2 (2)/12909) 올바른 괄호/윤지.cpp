#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<int> tmp;
    
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '('){
            tmp.push(s[i]);
        } else if (!tmp.empty() && s[i] == ')'){
            tmp.pop();
        } else {
            answer = false;
        }
    }
    
    if(!tmp.empty()){
        answer = false;
    }

    return answer;
}
