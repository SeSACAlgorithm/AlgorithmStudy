#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000];
int temp[1000];

void Input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

void Solve()
{
    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        int maxValue = 0;
        for(int j = 0; j < i; j++)
        {
            if(A[i] > A[j]) maxValue = max(maxValue, temp[j]);
        }
        temp[i] = maxValue + A[i];
        answer = max(answer, temp[i]);
    }

    cout << answer;
}

int main(void)
{
    Input();
    Solve();
}