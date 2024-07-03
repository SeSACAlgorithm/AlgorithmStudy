#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
int deg[32001];
int n, m;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		++deg[y];
	}


	queue<int> Q;

	for (int i = 1; i <= n; ++i)
	{
		if (deg[i] == 0) 
			Q.push(i);
	}


	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		cout << cur << ' ';

		for (auto& nxt : adj[cur])
		{
			--deg[nxt];

			if (deg[nxt] == 0)
				Q.push(nxt);

		}

	}
    
    return 0;
}

