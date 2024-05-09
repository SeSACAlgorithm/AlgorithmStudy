#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    // i 0부터 시작하면 x 포함 안됨
    for (int i = 1; i <= n; i++) {
        answer.push_back(x * i);
    }
    return answer;
}