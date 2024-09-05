#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    if (answer.size() == 1) {
        answer.erase(answer.begin(),answer.end());
        answer.push_back(-1);
    } else {
        // 최소값을 찾음
        auto minIt = min_element(answer.begin(), answer.end());
        
        // 최소값을 삭제
        answer.erase(minIt);
    }

    return answer;
}
