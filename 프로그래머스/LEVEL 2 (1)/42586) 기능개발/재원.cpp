#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while (!progresses.empty()) {
        // 매일 작업을 진행
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        int count = 0;

        // 맨 앞 작업이 완료되었는지 확인하고, 완료된 모든 작업을 배포
        while (!progresses.empty() && progresses[0] >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            count++;
        }

        // 완료된 작업이 있으면 그 개수를 기록
        if (count > 0) {
            answer.push_back(count);
        }
    }
    
    return answer;
}
