#include <vector>
#include <algorithm>
using namespace std;

// 두 수의 최대공약수
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 두 수의 최소공배수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0]; // 첫 번째 수로 초기화

    // 배열의 모든 요소에 대해 최소공배수 계산
    for (int i = 1; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }

    return answer;
}
