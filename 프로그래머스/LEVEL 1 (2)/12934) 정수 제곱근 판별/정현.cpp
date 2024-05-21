#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    // sqrt(��Ʈ�� ����)
    long long num = sqrt(n);

    if (num * num == n)
    {
        // pow(��, ����) ���·� n������ ���� ��ȯ
        answer = pow(num + 1, 2);
    }
    else
    {
        answer = -1;
    }
    return answer;
}