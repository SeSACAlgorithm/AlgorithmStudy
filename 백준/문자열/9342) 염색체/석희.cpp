#include <iostream>

using namespace std;

int T;

bool check_str(string str)
{
    int index = 0;
    int aCount = 0;
    int fCount = 0;
    int cCount = 0;

    if (!(str[0] >= 'A' && str[0] <= 'F') || !(str.back() >= 'A' && str.back() <= 'F')) return false;

    if(str[0] != 'A') index++;
    for(index; index < str.size(); index++)
    {
        if(str[index] != 'A') break;
        aCount++;
    }

    if(index >= str.size() || str[index] != 'F') return false;

    for(index; index < str.size(); index++)
    {
        if(str[index] != 'F') break;
        fCount++;
    }

    if(index >= str.size() || str[index] != 'C') return false;

    for(index; index < str.size(); index++)
    {
        if(str[index] != 'C') break;
        cCount++;
    }

    if(aCount == 0 || fCount == 0 || cCount == 0) return false;
    return true;
}

int main(void)
{
    string str;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> str;

        if (!check_str(str)) cout << "Good";
        else cout << "Infected!";
        cout << "\n";
    }
}