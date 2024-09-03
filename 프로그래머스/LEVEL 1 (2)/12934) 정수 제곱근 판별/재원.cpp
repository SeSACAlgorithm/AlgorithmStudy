#include <cmath>  // std::sqrt
using namespace std;

long long solution(long long n) {
    // 제곱근을 계산하여 정수로 변환
    long long root = static_cast<long long>(sqrt(n));
    
    // root의 제곱이 n과 같은지 확인
    if (root * root == n) {
        // 완전 제곱수인 경우 (root + 1)^2을 반환
        return (root + 1) * (root + 1);
    } else {
        // 완전 제곱수가 아닌 경우 -1을 반환
        return -1;
    }
}
