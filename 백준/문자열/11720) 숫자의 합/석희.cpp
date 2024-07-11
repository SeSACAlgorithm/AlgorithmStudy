#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int answer = 0;
    char num;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        answer = answer + (num - '0');
    }
    cout << answer;
}