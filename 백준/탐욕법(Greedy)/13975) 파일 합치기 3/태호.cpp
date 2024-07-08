#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;

	for (int t = 0; t < T; ++t)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		int n;  cin >> n;

		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			pq.push(x);
		}

		long long result = 0;

		while (pq.size() > 1)
		{
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();

			result += a + b;

			pq.push(a + b);
		}
		
		cout << result << '\n';
	}
		

	return 0;
}

