#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> list;
    // i 1부터 n까지 n을 나눠 나눠서 나머지가 0이면 약수
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            // 그 친구들을 모아
            list.push_back(i);
        }
    }
    // 모은 친구들 더해! 어떻게 더해?
    for (int j = 0; j < list.size(); j++) {
        answer += list[j];
    }
    return answer;
}