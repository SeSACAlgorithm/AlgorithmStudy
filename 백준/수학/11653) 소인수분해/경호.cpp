#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int num;
    cin >> num;

    int limit = sqrt(num);
    for (int i = 2; i <= limit; ++i)
    {
        while (num % i == 0)
        {
            cout << i << "\n";
            num /= i;
        }
    }

    if (num > 1)
        cout << num << "\n";
}