#include<iostream>

using namespace std;

bool isPrime(int x)
{
	if (x == 1)
		return false;
	int i = 2;
	while (i<x)
	{
		if (x % i == 0)
			return false;
		i++;
	}

	return true;
}

int main()
{
    int N ,M,sum,min;
    sum=0;
    min=0;
    
    cin>>N>>M;
    for(N;N<=M;N++)
    {
        if(isPrime(N))
        {
            sum+=N;
            if(min==0)
                min=N;
        }
    }
    if(sum==0)
    {
        cout<<-1;
    }
    else
    {
        cout<<sum<<endl;
        cout<<min<<endl;
    }
    return 0;
}
