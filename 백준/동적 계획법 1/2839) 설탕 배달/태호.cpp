#include <iostream>

using namespace std;

int n;
int result = 10000;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i <= n; i += 5)
    {
        int num = n - i;

        if(num % 3 == 0)
            result = min(result, num / 3 + i / 5);
    }
       
    cout << (result == 10000 ? -1 : result);
   
}
