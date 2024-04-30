#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for(int i = 0 ; i < s.size(); i++){
        if(i == 0){
            if (s[i] >= 'a' and s[i] <= 'z') s[i] = toupper(s[i]);
            answer += s[i];
            continue;
        }
        
        if( s[i-1] == ' '){
            if(s[i] >= 'a' && s[i] <= 'z') s[i] = toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }
        
        answer += s[i];
        
    }
    return answer;
}
