#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


    int N, M;
    cin >> N >> M;

    int bulb[4001] = {0, };

    for(int i=1; i<=N; i++)     // N개의 전구
        cin >> bulb[i];

    for(int i=0; i<M;i++)       // a, b, c 입력
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
            bulb[b] = c;

        else if(a == 2)
            for(int i=b; i<=c; i++)
                if(!bulb[i])
                    bulb[i] = 1;
                
                else
                    bulb[i] = 0;

        else if(a == 3)
            for(int i=b; i<=c; i++)
                bulb[i] = 0;

        else if(a == 4)
            for(int i=b; i<=c; i++)
                bulb[i] = 1;
    }    

    for(int i=1; i<=N; i++)
    {
        cout << bulb[i] << " " ;
    }
}



