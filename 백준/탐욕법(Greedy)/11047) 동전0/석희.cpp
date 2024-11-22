#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int coins[10];

int main(void)
{
    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    sort(coins, coins+N, greater<int>());

    int answer = 0;
    int i = 0;
    while(K > 0)
    {
        answer += (K / coins[i]);
        K = K % coins[i];
        i++;
    }

    cout << answer;
}