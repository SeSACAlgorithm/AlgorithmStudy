#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int year;
    cin >> year;

    if (year % 400 == 0)
    {
        cout << 1 << '\n';
        return 0;
    }
        

    if(year % 4 == 0 && year % 100 != 0)
    {
        cout << 1 << '\n';
        return 0;
    }

    cout << 0 << '\n';
}