#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    // sqrt(루트할 숫자)
    long long num = sqrt(n);

    if (num * num == n)
    {
        // pow(밑, 지수) 형태로 n제곱의 값을 반환
        answer = pow(num + 1, 2);
    }
    else
    {
        answer = -1;
    }
    return answer;
}