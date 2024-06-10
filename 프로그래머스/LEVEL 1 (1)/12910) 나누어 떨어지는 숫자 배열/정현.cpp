#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    //arr배열의 값들을 0부터 divisor로 나눈다
    for (int i = 0; i < arr.size(); i++) {
        //나눈 값이 0이라면 answer배열에 추가
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    //오름차순 정리
    sort(answer.begin(), answer.end());
    //answer배열이 비어있다면 -1 담기
    if (answer.empty()) {
        answer.push_back(-1);
    }
    return answer;
}