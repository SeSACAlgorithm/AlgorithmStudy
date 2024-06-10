#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum = 0;
    //�迭0��°���� �ϳ� �ϳ��� ���غ��� ��� answer�� �߰�
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    }
    // �������� ����
    sort(answer.begin(), answer.end());
    //���� �ߺ� ����
    //sort, unique, erase �Լ��� Ȱ���Ͽ� �ߺ� ���Ÿ� �� �� �ִ�.
    //unique �Լ��� ���ӵ� �ߺ� ���Ҹ� ������ ���� �޺κ����� ���������� �Լ��̴�. 
    //���� unique�Լ��� �����ϱ� ���� sort�� ���� ���ĵǾ� �־���ϰ� unique ���� �Ŀ��� erase�� ����
    //�� �κ��� �������־���Ѵ�.
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}