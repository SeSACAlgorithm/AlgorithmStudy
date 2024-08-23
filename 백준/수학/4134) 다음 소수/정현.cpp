#include <iostream>
using namespace std;

bool isPrime(long long num) 
{
    if (num <= 1) 
        return false;

    if (num == 2 || num == 3) 
        return true;
    
      // 2나 3으로 나누어지는 수는 소수가 아니다
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (long long i = 5; i * i <= num; i += 6) 
    {
        if (num % i == 0 || num % (i + 2) == 0) 
            return false;
    }

    return true;
}

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 

    long long N, n;
    cin >> N; 

    for (int i = 0; i < N; ++i)
    {
        cin >> n; 
       
        while (!isPrime(n))
            n++;

        cout << n << '\n'; 
    }

    return 0;
}
