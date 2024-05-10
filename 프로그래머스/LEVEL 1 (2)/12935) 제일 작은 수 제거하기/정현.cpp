#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0]; // 첫 번째 요소를 최소값으로 

    for (int i = 0; i < arr.size(); i++) {
        if (min > arr[i]) min = arr[i]; // 현재 최소값보다 작은 값이 있으면 그 값을 min으로
    }

   
    for (int i = 0; i < arr.size(); i++) {
        if (min != arr[i]) answer.push_back(arr[i]); // 최소값이 아닌 경우에만 answer에 추가
    }

    // 만약 answer 비어있으면 -1 추가
    if (answer.empty()) answer.push_back(-1);

    return answer;
}