// 문제 분석
/*
    20!의 값은 2.43 * 10^18
    long long의 최대값은 약 9.22 * 10^18

    즉, long long으로는 20! 까지 계산할 수 있다. (오버플로우가 발생하지 않는다)
*/

#include <iostream>

using namespace std;

int N;

long long Factorial(long long temp)
{
    if(temp <= 1) return 1;
    return Factorial(temp - 1) * temp;
}

int main(void)
{
    cin >> N;
    cout << Factorial(N);
}