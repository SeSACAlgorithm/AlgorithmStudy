#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//map 내림차순 정렬
bool desc(pair<int, double>& a, pair<int, double>& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> fail;
    
    for(int i = 1; i <= N; i++){
        int tot_cnt = 0;
        int fail_cnt = 0;
        
        // 도전한 플레이어, 실패한 플레이어 카운트
        for(int j = 0; j < stages.size(); j++){
            if(stages[j] >= i) tot_cnt++;
            if(stages[j] == i) fail_cnt++;
        }
        
        // 테스트 케이스 예외 처리
        if(tot_cnt != 0){
            fail[i] = (double)fail_cnt / tot_cnt ;
        } else {
            fail[i] = 0.0;
        }
        
    }
    
    // 실패율 기준으로 스테이지 번호 내림차순
    vector<pair<int, double>> sorted_fail(fail.begin(), fail.end());
    sort(sorted_fail.begin(), sorted_fail.end(), desc);

    for(int i = 0 ; i < sorted_fail.size(); i++){
        answer.push_back(sorted_fail[i].first);
    }
    
    return answer;
}
