#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int money[1000000];
long long answer = 0;

void Input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> money[i];
    }
}

void Solve()
{
    int maxNum = 0;
    answer = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        if(maxNum < money[i]) maxNum = money[i];
        else answer = answer + maxNum - money[i];
    }

    cout << answer << "\n";
}

int main(void)
{
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        Input();
        Solve();
    }
}