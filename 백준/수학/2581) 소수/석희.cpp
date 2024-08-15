#define INF 987654321

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main(void)
{
    int M, N;
    int sum = 0;
    int min_prime = INF;

    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        if (isPrime(i))
        {
            sum += i;
            min_prime = min(i, min_prime);
        }
    }

    if(min_prime == INF) cout << -1;
    else cout << sum << "\n" << min_prime;
}