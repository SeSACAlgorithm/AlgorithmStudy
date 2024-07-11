#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer; // [최고 순위, 최저 순위]
    
    int hit = 0;  // 맞춘 번호의 개수
    int none = 0; // 모르는 번호 개수 (0의 개수)
    
    for (auto& num : win_nums) {
        auto it = find(lottos.begin(), lottos.end(), num);
        if (it != lottos.end()){
            hit++;
        }
    }
    
    for (auto& num : lottos) {
        if (num == 0) none++;
    }
    
    // 맞은 개수 + 모르는 번호의 개수 = 최대 순위
    int max_hit = hit + none; 
    
    // 맞은 개수 = 최소 순위
    int min_hit = hit; 
    
    // 최소로 맞은 숫자의 개수가 1 or 0 이라면 낙첨
    if (min_hit < 2) min_hit = 1;
    
    // 최대로 맞은 숫자의 개수가 0 이라면 낙첨
    if (max_hit == 0) max_hit = 1;
    
    // 7에서 빼준 이유는 (순위 + hit) = 7 이기 때문
    answer.push_back(7-max_hit);
    answer.push_back(7-min_hit);
    
    // [최고 순위, 최저 순위] 반환
    return answer;
}
