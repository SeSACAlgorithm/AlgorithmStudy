#include "iostream"

using namespace std;

int N;

int solve()
{
    int n = 0;
    int result = 0;

    for(int i=0; i<N; i++)
    {
        int sum = 0;
        int num = i;

        while(num != 0)
        {
            sum += num % 10;
            num /= 10;
        }

        if(i + sum == N)
        {
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    cin >> N;

    cout << solve();    
}