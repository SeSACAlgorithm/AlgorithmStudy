#include <iostream>

using namespace std;

int A, T;
int word; // 뻔 : 0, 데기 : 1

void Input()
{
    cin >> A;
    cin >> T;
    cin >> word;
}

int Solve()
{
    int wordCount0 = 0, wordCount1 = 0;
    int round = 2;

    while (true)
    {
        // 뻔 데기 뻔 데기 구간
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 == 0) wordCount0++;
            else wordCount1++;

            if ((wordCount0 == T && word == 0) || (wordCount1 == T && word == 1))
                return (wordCount0 + wordCount1 - 1) % A;
        }
        // 뻔 뻔 데기 데기 구간
        for (int i = 0; i < round; i++)
        {
            wordCount0++;
            if (wordCount0 == T && word == 0) return (wordCount0 + wordCount1 - 1) % A;
        }

        for (int i = 0; i < round; i++)
        {
            wordCount1++;
            if (wordCount1 == T && word == 1) return (wordCount0 + wordCount1 - 1) % A;
        }

        round++;
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    if (A == 1) cout << "0";
    else cout << Solve();
}