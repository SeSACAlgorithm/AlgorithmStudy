#include "iostream"
#include "queue"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> Q;
	queue<int> rQ;

	int N; // 7
	int K; // 3
	int temp;
	int count = 1;

	cin >> N >> K;
	// {1, 2, 3, 4, 5, 6, 7}
	for (int i = 1; i <= N; i++)
	{
		if (count == K)
		{
			count = 1;
			rQ.push(i);
		}

		else
		{
			Q.push(i);
			count++;
		}
	}
	// Q={1,2,4,5,7}
	// rQ={3,6}
	// count = 2
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();

		if (count == K)
		{
			count = 1;
			rQ.push(temp);
		}

		else
		{
			count++;
			Q.push(temp);
		}
	}
	cout<<"<";

	while(!rQ.empty())
	{
		cout<<rQ.front();
		rQ.pop();
		if(rQ.size()>=1)
		{
			cout<<", ";
		}
	}
	cout<<">";
}
