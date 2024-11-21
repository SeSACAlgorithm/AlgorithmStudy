// 문제 분석
/*
    
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rope[100000];

void Input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> rope[i];
    }
}

void Solve()
{
    int answer = 0;

    sort(rope, rope + n);
    for(int i = 0; i < n; i++)
    {
        answer = max(answer, rope[i] * (n - i));
    }

    cout << answer;
}

int main(void)
{
    Input();
    Solve();
}