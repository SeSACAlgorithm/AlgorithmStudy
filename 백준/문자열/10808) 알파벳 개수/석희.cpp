#include <iostream>
#include <string>

using namespace std;

int alphabet_count[27];

int main(void)
{
    string S;

    cin >> S;

    for (int i = 0; i < S.length(); i++)
    {
        alphabet_count[S[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet_count[i] << " ";
    }
}