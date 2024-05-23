#include "iostream"

using namespace std;

int main()
{
    int N;
    cin >> N;

    int original = N;
    int result = -1;
    int a, b, c;
    int cnt = 0;

    while (original != result)
    {
        if(N < 10)
        {
            a = N;
            b = 0;
        }

        else
        {
            a = N % 10;
            b = N / 10;
        }

        c = a + b;
        c = c % 10;

        result = a*10 + c;

        N = result;

        cnt++;
    }
    cout << cnt;
}

