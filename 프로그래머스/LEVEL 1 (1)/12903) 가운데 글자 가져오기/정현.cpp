#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    //¦���� ��� ��� �α���
    //Ȧ���� ��� ��� �ѱ��� <- �̰� ¦���� Ȧ���� ������ �߰��ؾ���
    // ¦���� ���
    if (s.size() % 2 == 0)
    {
        // ��� ù��° ����
        answer += s[s.size() / 2 - 1];
    }
    // ��� ����
    answer += s[s.size() / 2];
    return answer;
}
