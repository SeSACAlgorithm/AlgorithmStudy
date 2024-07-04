#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
int depth[1001];
int result[1001];

int n, m;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		++depth[b];
	}

	queue<pair<int, int>> Q;

	for (int i = 1; i <= n; ++i)
	{
		if (depth[i] == 0)
			Q.push({ i, 0 });
	}


	while (!Q.empty())
	{
		pair<int,int> cur = Q.front(); Q.pop();
		result[cur.first] = cur.second;

		for (int nxt : adj[cur.first])
		{
			--depth[nxt];

			if (depth[nxt] == 0)
				Q.push({ nxt, cur.second + 1 });
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << result[i] + 1 << ' ';


	return 0;
}
