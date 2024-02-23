#include "iostream"
#include "queue"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> Q;
	int N;
	int result;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Q.push(i);
	}

	while (Q.size() != 1)
	{
		Q.pop();
		result = Q.front();
		Q.pop();
		Q.push(result);
	}

	cout << Q.front();
}