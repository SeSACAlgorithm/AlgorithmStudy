#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int main()
{
    while (1)
    {
        getline(cin, s);

        if(s == "END")
            break;

        reverse(s.begin(), s.end());

        cout << s << "\n";
    }

    return 0;
}