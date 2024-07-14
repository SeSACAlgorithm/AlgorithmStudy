#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, st, en;

constexpr int INF = 0x7f7f7f7f;

vector<pair<int, int>> adj[1002];
int d[1002];

int main()
{
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b, dist; cin >> a >> b >> dist;
		adj[a].push_back({ dist, b });
	}

	cin >> st >> en;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	fill(d + 1, d + 1 + v, INF);
	d[st] = 0;

	pq.push({d[st], st});

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();

		if(cur.first != d[cur.second]) continue;

		for (auto nxt : adj[cur.second])
		{
			int sum = nxt.first + d[cur.second];

			if (d[nxt.second] > sum)
			{
				d[nxt.second] = sum;
				pq.push({ sum, nxt.second });
			}
		}
	}

	cout << d[en];

}
