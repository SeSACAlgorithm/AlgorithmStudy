#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int TargetIndex=s.size()/2;
   
    if(s.size()%2==0)//짝수일때 
    {
        answer+=s[TargetIndex-1];
        answer+=s[TargetIndex];
        
    }
    else//홀수 일때
    {
        answer+=s[TargetIndex];
    }
    
    return answer;
}
