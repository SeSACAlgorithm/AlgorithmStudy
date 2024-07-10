#include <iostream>
#include <string>

using namespace std;

int main()
{
    string N;
    int B;
    cin >> N >> B;

    char offset = 'A' - 10;
    int res = 0, cur = 0;
    int multiplier = 1;
    for(auto it = N.rbegin(); it != N.rend(); ++it)
    {
        cur = isdigit(*it) ? *it - '0' : *it - offset;
        res += cur * multiplier;
        multiplier *= B;
    }

    cout << res;
}