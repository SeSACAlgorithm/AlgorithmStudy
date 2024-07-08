#include <iostream>

using namespace std;

int main()
{
    int origin;
    cin >> origin;
    if (origin < 10) origin *= 10;

    int count = 0;
    int cur = origin;
    while(true)
    {
        int front = cur / 10;
        int back = cur % 10;
        cur = (back * 10) + (front + back) % 10;

        ++count;
        if (cur == origin) break;
    }

    cout << count;
}