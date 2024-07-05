#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> adj[1001];
int timer[1001];
int timestack[1001];
int depth[1001];

int t;

int main()
{
	cin >> t;

	ios::sync_with_stdio(0); cin.tie(0);


	for (int i = 0; i < t; ++i)
	{
		int n, m; cin >> n >> m;

		for (int j = 0; j < n; ++j)
		{
			depth[j] = 0;
			adj[j].clear();
		}

		for (int j = 1; j <= n; ++j)
		{
			cin >> timer[j];
			timestack[j] = 0;
		}

		for (int j = 0; j < m; ++j)
		{
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			++depth[b];
		}

		int result; cin >> result;

		queue<pair<int, int>> Q;

		for (int j = n; j > 0; --j)
		{
			if (depth[j] == 0)
			{
				Q.push({ j, timer[j] });
				timestack[j] = timer[j];
			}
				
		}

		while (!Q.empty())
		{
			pair<int, int> cur = Q.front(); Q.pop();

			if (result == cur.first)
			{
				cout << timestack[cur.first] << '\n';
				break;
			}

			for (int nxt : adj[cur.first])
			{
				--depth[nxt];
			
				timestack[nxt] = max(timestack[nxt], cur.second + timer[nxt]);

				if (depth[nxt] == 0)
				{
					Q.push({ nxt, timestack[nxt] });
				}
			}
		}
	}


	return 0;
}

