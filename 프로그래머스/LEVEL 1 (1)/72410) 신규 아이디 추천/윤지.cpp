#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for(int i = 0 ; i < new_id.size(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z' ){
            answer += tolower(new_id[i]);
        } else {
            // 2단계
            if( (new_id[i] >= 'a' && new_id[i] <= 'z') || 
                (new_id[i] >= '0' && new_id[i] <= '9') ||
                 new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' ){
                answer += new_id[i];
            }
            
        }
    }
    
    // 3단계
    string tmp = "";
    for(int i = 0 ; i < answer.size(); i++){
        if(answer[i] == '.' && answer[i+1] == '.'){
            continue;
        }
        tmp += answer[i];
    }
    answer = tmp;
    
    // 4단계
    if(answer.front() == '.') answer.erase(0,1);
    if(answer.back() == '.') answer.pop_back();
    
    // 5단계
    if(answer == "") answer = "aaa";
    
    // 6단계
    if(answer.size() >= 16){
        answer = answer.substr(0, 15);
        if(answer.back() == '.') answer.pop_back();
    }
    
    // 7단계
    if(answer.size() <= 2){
        while(answer.size() < 3){
            answer += answer.back();
        }
    }
    
    return answer;
}
