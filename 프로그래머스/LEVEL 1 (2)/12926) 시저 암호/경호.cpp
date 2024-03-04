#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    char temp = ' ';
    int idx = 0;
    for(char c : s)
    {
        temp = c + n;
        idx = c + n;
        
        if(c == ' ') 
            temp = ' ';
        else if(isupper(c) && idx > 'Z')
            temp -= 26;    
        else if(islower(c) && idx > 'z')
            temp -= 26; 
           
        answer += temp;
    }
    return answer;
}