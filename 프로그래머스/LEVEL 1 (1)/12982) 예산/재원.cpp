#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    // 오름차순 정리
    sort(d.begin(), d.end());
    
    int sum = 0;
    for (int i = 0; i < d.size(); i++) {
        sum += d[i];
        if (sum > budget) {
            break;
        }
        answer++;
    }
    
    return answer;
}

int main() {
    vector<int> d = {1, 3, 2, 5, 4};
    int budget = 9;
    cout << "지원 가능한 부서 수: " << solution(d, budget) << endl; // 예상 결과는 3
    return 0;
}

//1.d를 내림차순 정리한다
//2.작은 숫자부터 누적 합을 더해가며 budget을 넘길때의 d의 요소위치를 구한다
