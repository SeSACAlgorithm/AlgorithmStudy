#include <iostream>

using namespace std;

long long N, S;

void Solve()
{
    long long sum = 0;
    for(long long i = 1; i <= S; i++)
    {
        if(sum + i <= S)
        {
            sum = sum + i;
            N = i;
        }
        else break;
    }
    cout << N;
}


int main(void)
{
    cin >> S;
    Solve();
}