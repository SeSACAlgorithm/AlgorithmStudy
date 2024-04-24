#include <string>
#include <vector>
#include <iostream>

using namespace std;


string getBinary(int n)
{
    string strBinary = "";
    
    while(n > 0)
    {
        int remain = n % 2;
        n /= 2;
        strBinary += to_string(remain);
    }
    
    return strBinary;
}

int countOne(const string& s)
{
    int cnt = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '1')
            ++cnt; 
    }
    
    return cnt;
}




int solution(int n) {
    int answer = 0;
    string start = getBinary(n);
    int one = countOne(start);

    for(int i=n+1;;i++){
        string binary = getBinary(i);
        if(one==countOne(binary)){
            answer=i;
            break;
        }
    }    

    return answer;
}
