#include <string>
#include <iostream>
using namespace std;
//조건 py개수 같음,py 개수 0 = true  개수 다름=false
// 1. string s의 크기만큼 각 인덱스에 접근하여 개수를 센다 
// 2. 반복이 끝나면 개수 비교 
bool solution(string s)
{
    bool answer = true;

    int pCount=0;
    int yCount=0;
    
 
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='p'||s[i]=='P')
        {
            pCount++;
        }
        else if(s[i]=='y'||s[i]=='Y')
        {
            yCount++;
        }
        
    }
    
    if(pCount==yCount)
    {
        
        
        answer=true;
    }
    else
    {
        answer=false;
    }
    

    return answer;
}
