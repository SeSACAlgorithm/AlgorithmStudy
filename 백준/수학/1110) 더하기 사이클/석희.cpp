#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N, n, num;
    int new_num = -1;
    int count = 0;

    cin >> N;

    num = N;
    while (new_num != N)
    {
        if (new_num != -1)
            num = new_num;
        n = (num / 10) + (num % 10);
        new_num = ((num % 10) * 10) + (n % 10);
        count++;
    }
    cout << count;
}