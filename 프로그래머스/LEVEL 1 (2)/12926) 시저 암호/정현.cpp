#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        // ������ ��� �״�� �߰�
        if (c == ' ') {
            answer += c;
        }
        // �빮���� ���
        else if (c >= 'A' && c <= 'Z') {
            // 'Z'�� �Ѿ�� ��� A�� ����
            if (c + n > 'Z') {
                answer += c + n - 26;
            }
            else {
                answer += c + n;
            }
        }
        // �ҹ����� ���
        else if (c >= 'a' && c <= 'z') {
            // 'z'�� �Ѿ�� ��� a�� �Ѿ��
            if (c + n > 'z') {
                answer += c + n - 26;
            }
            else {
                answer += c + n;
            }
        }
    }
    return answer;
}
