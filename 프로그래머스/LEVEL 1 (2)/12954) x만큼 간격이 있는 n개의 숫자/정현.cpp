#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    // i 0���� �����ϸ� x ���� �ȵ�
    for (int i = 1; i <= n; i++) {
        answer.push_back(x * i);
    }
    return answer;
}