#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    // answer�迭�� arr[0] ���� �߰�
    answer.push_back(arr[0]);
    // arr�迭 ũ�� ��ŭ �ݺ�
    for (int i = 1; i < arr.size(); i++) {
        // ���� �߰��ҷ��� ���� ���� �߰��� ���� �ٸ��ٸ� �߰�
        if (arr[i] != arr[i - 1]) {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}