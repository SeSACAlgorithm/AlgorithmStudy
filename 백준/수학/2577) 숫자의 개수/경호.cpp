#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> digits(10, 0);
    int mul = A * B * C;
    while(mul > 0)
    {
        ++digits[mul % 10];
        mul /= 10;
    }

    for (const int& digit : digits)
        cout << digit << "\n";
}