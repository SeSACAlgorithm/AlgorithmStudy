#include <iostream>

using namespace std;
int n;
int d[31][31];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[0][0] = 1;

    for (int i = 1; i <= 30; ++i)
    {
        d[i][0] = 1;

        for (int j = 1; j <= i; ++j)
        {
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }


    while (n--)
    {
        int a, b; cin >> a >> b;
        cout << d[b][a] << '\n';
    }
      
   
}
