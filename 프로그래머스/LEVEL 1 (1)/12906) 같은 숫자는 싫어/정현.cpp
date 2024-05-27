#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    // answer배열에 arr[0] 원소 추가
    answer.push_back(arr[0]);
    // arr배열 크기 만큼 반복
    for (int i = 1; i < arr.size(); i++) {
        // 만약 추가할려는 수가 전에 추가한 수와 다르다면 추가
        if (arr[i] != arr[i - 1]) {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}