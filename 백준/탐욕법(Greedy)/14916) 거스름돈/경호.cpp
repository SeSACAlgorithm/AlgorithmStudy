#include <iostream>

using namespace std;

#define FIVE 5
#define TWO 2

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int money;
    cin >> money;

    int div = money / FIVE;
	int remain = money % FIVE;
    while(div >= 0)
    {
	    if(remain % TWO == 0)
	    {
            remain /= TWO;
            break;
	    }

        --div;
        remain += FIVE;
    }

    if (div < 0) cout << -1;
    else         cout << div + remain;
}