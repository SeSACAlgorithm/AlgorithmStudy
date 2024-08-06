#define MAX 123456789

#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int answer = MAX;
    int count = 0;

    cin >> n;

    if (n % 5 == 0)
    {
        cout << n / 5;
        return 0;
    }

    while (n > 0)
    {
        if (n % 2 == 0) answer = n / 2 + count;
        count++;
        n = n - 5;
    }

    cout << (answer == MAX ? -1 : answer);
}