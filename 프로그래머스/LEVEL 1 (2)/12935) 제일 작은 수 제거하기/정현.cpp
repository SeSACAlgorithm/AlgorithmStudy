#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0]; // ù ��° ��Ҹ� �ּҰ����� 

    for (int i = 0; i < arr.size(); i++) {
        if (min > arr[i]) min = arr[i]; // ���� �ּҰ����� ���� ���� ������ �� ���� min����
    }

   
    for (int i = 0; i < arr.size(); i++) {
        if (min != arr[i]) answer.push_back(arr[i]); // �ּҰ��� �ƴ� ��쿡�� answer�� �߰�
    }

    // ���� answer ��������� -1 �߰�
    if (answer.empty()) answer.push_back(-1);

    return answer;
}