#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> tmp;
    vector<int> score;
    
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] == '1' && dartResult[i+1] == '0'){
            tmp.push_back("10");
            i++;
        } else {
            string text = "";
            text = dartResult[i];
            tmp.push_back(text);
        }
    }
    
    for(int i = 0; i < tmp.size(); i++){
        int score_tmp = 0;
        int score_index = score.size()-1;
        
        if(tmp[i] >= "0" && tmp[i] <= "9" || tmp[i] == "10" ){
            score_tmp = stoi(tmp[i]);
            score.push_back(score_tmp);
        } else if(tmp[i] == "S"){
            score_tmp = pow(score[score_index], 1);
            score[score_index] = score_tmp;
        } else if(tmp[i] == "D"){
            score_tmp = pow(score[score_index], 2);
            score[score_index] = score_tmp;
        } else if(tmp[i] == "T"){
            score_tmp = pow(score[score_index], 3);
            score[score_index] = score_tmp;
        }
        
        if(tmp[i] == "*"){
            if(score.size() == 1){
                score[score_index] *= 2;
            } else {
                score[score_index] *= 2;
                score[score_index - 1] *= 2;
            }
            
        } else if(tmp[i] == "#"){
            score[score_index] *= -1;
        }
    }
    
    for(int i = 0 ; i < score.size(); i++){
        answer += score[i];
    }
    
    
    return answer;
}
