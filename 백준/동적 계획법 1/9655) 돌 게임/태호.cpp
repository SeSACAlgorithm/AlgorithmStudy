#include <iostream>

using namespace std;

int n;

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    if(n % 2 == 0)
        cout << "CY";
    else
        cout << "SK";


    return 0;
}

