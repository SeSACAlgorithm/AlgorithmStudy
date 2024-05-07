// 전체 스테이지 수 : N
// 실패율 : 스테이지에 도달했으나 아직 클리어X 플레이어의 수 / 스테이지 도달 플레이어 수
// 멈춰있는 스테이지 번호 stages[]

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 실패율이 높은 스테이지부터 내림차순 return
bool compare(pair<int, double>& a, pair<int, double>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> ans;
    map<int, double> fail;
    
    for(int i=1; i<=N; i++)
    {
        int fail_cnt = 0;   // 실패한 사람
        int try_cnt = 0;    // 시도한 사람
        
        for(int j=0; j<stages.size(); j++)
        {
            if(stages[j] == i)
                fail_cnt++;  // 스테이지에 머문 사람
            
            if(stages[j] >= i)
                try_cnt++;   // 스테이지에 도달한 사람
        }
        
        if(try_cnt != 0)
            fail[i] = (double)fail_cnt / try_cnt; // 실패율
        
        else
            fail[i] = 0.0;
    }
    
    // map을 vector로 변환
    vector<pair<int, double>> sorted_fail(fail.begin(), fail.end());
    // 변환된 vector compare함수로 정렬
    sort(sorted_fail.begin(), sorted_fail.end(), compare);
    
    for(int i=0; i<sorted_fail.size(); i++)
        ans.push_back(sorted_fail[i].first);
    
    return ans;
}
