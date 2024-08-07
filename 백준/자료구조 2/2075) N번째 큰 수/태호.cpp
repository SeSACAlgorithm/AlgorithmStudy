#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;


	for (int i = 0; i < n; ++i)
	{
		int x;  cin >> x;
		pq.push(x);
	}
		

	for (int i = 0; i < n * n - n; ++i)
	{
		int x;  cin >> x;

		if (x > pq.top())
		{
			pq.pop();
			pq.push(x);
		}
	}

	cout << pq.top();

	return 0;
}

