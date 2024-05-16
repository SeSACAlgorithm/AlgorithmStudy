#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    bool temp[1000000] = { 0 };  // 1000000 ũ���� �迭�� false
    for (int i = 2; i <= n; i++) {  // 2���� n���� �ݺ�
        if (temp[i])  // ���� temp[i]�� true�̸� �̹� �Ҽ��� �ƴ�
            continue;  // ���� ���ڷ� �ǳʶ�
        answer++;  // �Ҽ� ���� ����
        for (int j = i; j <= n; j += i) {  // i�� ����� ��� true�� ����
            temp[j] = true;  // i�� ����� �Ҽ��� �ƴ�
        }
    }
    return answer;  // �Ҽ��� ���� ��ȯ
}