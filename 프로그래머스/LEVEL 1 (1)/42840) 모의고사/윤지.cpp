#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> tmp1 = {1,2,3,4,5};
    vector<int> tmp2 = {2,1,2,3,2,4,2,5};
    vector<int> tmp3 = {3,3,1,1,2,2,4,4,5,5};
    
    int score1 = 0 ;
    int score2 = 0 ;
    int score3 = 0 ;
    
    for(int i = 0; i < answers.size(); i++){
        if( answers[i] == tmp1[i % tmp1.size()])  score1++  ;
        if( answers[i] == tmp2[i % tmp2.size()])  score2++  ;
        if( answers[i] == tmp3[i % tmp3.size()])  score3++  ;
        
    }
     
    int maxCnt = max(score1, score2);
    maxCnt = max(maxCnt, score3);
        
    if(maxCnt == score1) answer.push_back(1);
    if(maxCnt == score2) answer.push_back(2);
    if(maxCnt == score3) answer.push_back(3);
    
    return answer;
}
