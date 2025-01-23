
#include <iostream>

using namespace std;

int K;
long long N;
long long lanCable[10000];
long long maxLan = 0;
long long answer = 0;

void Input()
{
    cin >> K >> N;

    for (int i = 0; i < K; i++)
    {
        cin >> lanCable[i];
        maxLan = max(lanCable[i], maxLan);
    }
}

bool CheckBigger(long long mid)
{
    long long sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += lanCable[i] / mid;
    }
    return sum >= N;
}

void binary_search()
{
    long long left = 1;
    long long right = maxLan;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (CheckBigger(mid))
        {
            left = mid + 1;
            answer = max(answer, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
}

int main(void)
{
    Input();
    binary_search();
}
