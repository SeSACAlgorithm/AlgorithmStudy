#include <iostream>
#include <algorithm>

using namespace std;

int number[10];
int main(void)
{
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '9' || str[i] == '6')
        {
            if (number[6] < number[9]) number[6]++;
            else number[9]++;
        }
        else number[str[i] - '0']++;
    }

    int max_count = 0;
    for (int i = 0; i <= 9; i++)
    {
        max_count = max(number[i], max_count);
    }

    cout << max_count;
}