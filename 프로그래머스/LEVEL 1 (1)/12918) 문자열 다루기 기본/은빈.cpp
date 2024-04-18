#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() == 4 || s.size() == 6){
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i]) != 0) return false;
        }   
        return true;
    }
    else return false;
    
    
}