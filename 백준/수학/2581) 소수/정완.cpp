#include "iostream"

using namespace std;

int main()
{
    int M, N;
    int sum = 0;
    int Min = -1;
    int cnt = 0;
    cin >> M >> N;

    for(int i=M; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i % j == 0)
                cnt++;
        }
        
        if(cnt == 2)
        {
            if(Min == -1)
                Min = i;
            sum += i;
        }

        cnt = 0;
    }

    if (Min == -1)
		cout << -1 << '\n';
	else
		cout << sum << '\n' << Min << '\n';
}