#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // �����ڵ� ���� ���� ��
    int a = 0;
    int b = 0;
    int c = 0;
    // �����ڵ� ���� ����
    vector<int> num1 = { 1, 2, 3, 4, 5 };
    vector<int> num2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> num3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    // ���� ����� �����̶� �� Ȯ��
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == num1[i % num1.size()]) a++;
        if (answers[i] == num2[i % num2.size()]) b++;
        if (answers[i] == num3[i % num3.size()]) c++;
    }

    // ���� ���� ���� ��� ã��
    int highscore = max(a, b);
    highscore = max(highscore, c);

    // ���� ���� ���� ��� answer�� �������
    if (highscore == a) answer.push_back(1);
    if (highscore == b) answer.push_back(2);
    if (highscore == c) answer.push_back(3);

    return answer;
}