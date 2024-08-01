#include <iostream>
#include <string>

using namespace std;

bool check_K(int time, int K)
{
    return (time / 10 == K || time % 10 == K);
}

int main(void)
{
    int N, K;
    int answer = 0;

    cin >> N >> K;

    for (int h = 0; h <= N; h++)
    {
        for (int m = 0; m < 60; m++)
        {
            for (int s = 0; s < 60; s++)
            {
                if (check_K(h, K) || check_K(m, K) || check_K(s, K)) answer++;
            }
        }
    }

    cout << answer;
}