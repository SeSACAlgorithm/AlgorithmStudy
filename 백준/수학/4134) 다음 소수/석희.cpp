#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long num)
{
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main(void)
{
    int T; // 테스트 케이스 개수
    long long n; // 입력 받을 수

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;

        // 소수가 나올때까지 증가하면서 찾기
        int index = 0;
        while (!isPrime(n + index))
            index++;

        // 소수가 나와서 while문을 빠져나왔다면 출력
        cout << n + index << "\n";
    }
}