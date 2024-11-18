#include <iostream>
#include <algorithm>

using namespace std;

int N;
int money[100000];

void Solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> money[i];
    }

    sort(money, money + N, greater<int>());

    long long answer = 0;
    for(int i = 0; i < N; i++)
    {
        long long tip = money[i] - i;
        if(tip > 0) answer += tip;
    }

    cout << answer;
}

int main(void)
{
    Solve();
}