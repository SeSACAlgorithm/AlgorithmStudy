#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failRates; // 실패율을 저장할 벡터

    for (int i = 1; i <= N; i++) {
        int DoNotClearPlayer = 0;
        int ConnectStagePlayer = 0;
        
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i)
                DoNotClearPlayer++;
            if (stages[j] >= i)
                ConnectStagePlayer++;
        }
        
        double failRate = 0.0;
        if (ConnectStagePlayer > 0) {
            failRate = static_cast<double>(DoNotClearPlayer) / ConnectStagePlayer;
        }
        
        failRates.push_back({i, failRate});
    }
    
    // 실패율을 기준으로 내림차순 정렬, 실패율이 같으면 스테이지 번호가 작은 것이 앞으로 오도록 정렬
    sort(failRates.begin(), failRates.end(), [](pair<int, double>& a, pair<int, double>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    
    for (auto& p : failRates) {
        answer.push_back(p.first);
    }
    
    return answer;
}

int main() {
    int N = 5;
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    vector<int> result = solution(N, stages);
    
    for (int stage : result) {
        cout << stage << " ";
    }
    cout << endl;
    
    return 0;
}








