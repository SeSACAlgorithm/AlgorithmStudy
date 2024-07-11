#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // 나머지로 나타내면 되지 않을까?
    // 찍기배열
    int a[] = {1,2,3,4,5};
    int b[] = {2,1,2,3,2,4,2,5};
    int c[] = {3,3,1,1,2,2,4,4,5,5};
    // 점수
    int as = 0;
    int bs = 0;
    int cs = 0;

    for (int i = 0; i < answers.size(); ++i){
        if(answers[i] == a[i%5])
            ++as;
        if(answers[i] == b[i%8])
            ++bs;
        if(answers[i] == c[i%10])
            ++cs;
    }
    
    int maxscore = max({as,bs,cs});
    
    if(as == maxscore)
        answer.push_back(1);
    if(bs == maxscore)
        answer.push_back(2);
    if(cs == maxscore)
        answer.push_back(3);
    
    return answer;
}


