#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    // ���ڿ��� ���̰� 4Ȥ�� 6�� �ƴϸ� false
    if (s.size() != 4 && s.size() != 6)
        answer = false;
    // ���ڿ��� ���ڷθ� �����Ǿ� ���� �ʴٸ� false
    // �ƽ�Ű�ڵ�� 0~9 �� 0~9!!
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            answer = false;
    }
    return answer;
}