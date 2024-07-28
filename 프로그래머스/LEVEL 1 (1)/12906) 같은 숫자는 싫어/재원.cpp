#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    // 첫 번째 요소를 무조건 추가
    answer.push_back(arr[0]);
    
    // 두 번째 요소부터 끝까지 순회
    for (int i = 1; i < arr.size(); ++i) {
        // 현재 요소가 직전 요소와 다를 때만 추가
        if (arr[i] != arr[i - 1]) {
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}

int main() {
    vector<int> arr = {1, 1, 3, 3, 0, 1, 1};
    vector<int> result = solution(arr);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
