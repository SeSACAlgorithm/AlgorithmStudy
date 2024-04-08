#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == ' ') {
            answer += ' ';
            continue;
        }
        
        int tmp = s[i] ;
        n %= 26;
        tmp = tmp + n;
        
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(tmp > 'Z' ){
                tmp = tmp - 'Z' + 'A' - 1;
            }
        }
        
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(tmp > 'z' ){
                tmp = tmp - 'z' + 'a' - 1;
            }
        }
        
        char a = tmp ;
        answer += a;
            
    }
    
    return answer;
}
