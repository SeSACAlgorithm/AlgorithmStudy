#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int v, e, k;

vector<pair<int, int>> edge[20002];
int d[20002];

constexpr int INF = 0x7f7f7f7f;

int main()
{
	cin >> v >> e >> k; 

	cin.tie(NULL); ios_base::sync_with_stdio(false);


	for (int i = 1; i <= e; ++i)
	{
		int a, b, dist; cin >> a >> b >> dist;
		edge[a].push_back({dist, b});
	}

	fill(d, d + v + 1, INF);
	
	d[k] = 0;

	priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (auto nxt : edge[k])
	{
		if(d[nxt.second] > nxt.first)
		{
			pq.push({ nxt.first, nxt.second });
			d[nxt.second] = nxt.first;
		}
		
	}
		
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); pq.pop();

		if (d[cur.second] != cur.first)
			continue;


		for (auto nxt : edge[cur.second])
		{
			int tmp = d[cur.second] + nxt.first;

			if(d[nxt.second] > tmp)
				d[nxt.second] = tmp;

			 if (d[cur.second] == cur.first)
				 pq.push({ d[cur.second] + nxt.first, nxt.second });
		}
	}

	for (int i = 1; i <= v; ++i)
		d[i] == INF ?  cout << "INF\n" : cout << d[i] << "\n";

}
