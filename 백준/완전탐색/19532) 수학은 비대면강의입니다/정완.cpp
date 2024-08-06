#include<iostream>

using namespace std;

int solve(int a, int b, int c, int d, int e, int f)
{
    for (int i = -999; i <= 999; i++)
    {
        for (int j = -999; j <= 999; j++)
        {
            if ((i * a + j * b == c) && (i * d + j * e == f))
            {
                cout << i << " " << j;
                return 0;
            }

            else
                continue;
        }
    }
}

int main(void) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    solve(a, b, c, d, e, f);
    return 0;
}