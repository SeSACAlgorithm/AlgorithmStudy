#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> list;
    // i 1���� n���� n�� ���� ������ �������� 0�̸� ���
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            // �� ģ������ ���
            list.push_back(i);
        }
    }
    // ���� ģ���� ����! ��� ����?
    for (int j = 0; j < list.size(); j++) {
        answer += list[j];
    }
    return answer;
}