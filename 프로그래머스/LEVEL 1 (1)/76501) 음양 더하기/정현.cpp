#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < signs.size(); i++) {
        // singns[i]�� true ���
        if (signs[i]) {
            // �״�� ���ϱ�
            answer += absolutes[i];
        }
        // signs[i]�� false���
        else {
            // �����ϱ� ����
            answer -= absolutes[i];
        }
    }

    return answer;
}