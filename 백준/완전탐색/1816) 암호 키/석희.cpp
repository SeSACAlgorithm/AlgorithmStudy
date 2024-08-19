// 문제 분석
/*
    10^6보다 큰 소수이면 매우 큰 소수로 생각
    어떤 수 S
    적절한 암호 키인지 아닌지 구하기
    S의 모든 소인수가 10^6보다 크다면 그 수는 적절한 암호키

    * 아이디어 *
    반대로 생각하기 -> 주어진 수에서 10^6보다 작은 소인수가 있다면 옳지 않은 수인 것.
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool check_password(long long n)
{
    double range = min(sqrt(n), 1000000.0);

    if (n < 2) return false;

    for (long long i = 2; i <= range; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int main(void)
{
    int N;       // 수의 개수 (1 ~ 10)
    long long S; // 확인하고자 하는 수 (10^12 ~ 10^18)

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S;

        if (check_password(S)) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}