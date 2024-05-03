#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;

    // ���ڸ� ���� �ڸ����� ���ʴ�� �迭�� �߰�
    while (n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }
    // ���� ������������ ����
    sort(arr.begin(), arr.end(), greater<int>());
    // ���ĵ� �迭�� ��Ҹ� answer�� ���� �ڸ����� ���ʴ�� �߰�
    for (int i = 0; i < arr.size(); i++) {
        answer *= 10; // �̰� �����ָ� ��� ���� ���ϰ� �ȴ�. �Ʒ��� ������ ó�� ���� 10�� �������� ���ϴ� ��°� *10��
        answer += arr[i];
    }

    return answer;

}