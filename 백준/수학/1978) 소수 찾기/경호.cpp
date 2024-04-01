#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count = 0;
    cin >> count;

    int num = 0;
    int answer = 0;
    for(int i = 0; i < count; i++)
    {
        cin >> num;
        if (num < 2) continue;

        int limit = sqrt(num);
        bool isPrime = true;
        for(int j = 2; j <= limit; j++)
        {
	        if(num % j == 0)
	        {
                isPrime = false;
                break;
	        }
        }
        if (isPrime) answer++;
    }

    cout << answer << '\n';
}