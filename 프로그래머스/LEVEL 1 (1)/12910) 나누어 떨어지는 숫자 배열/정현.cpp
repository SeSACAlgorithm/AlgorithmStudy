#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    //arr�迭�� ������ 0���� divisor�� ������
    for (int i = 0; i < arr.size(); i++) {
        //���� ���� 0�̶�� answer�迭�� �߰�
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    //�������� ����
    sort(answer.begin(), answer.end());
    //answer�迭�� ����ִٸ� -1 ���
    if (answer.empty()) {
        answer.push_back(-1);
    }
    return answer;
}