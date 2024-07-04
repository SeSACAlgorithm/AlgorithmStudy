#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> adj[32001];
int depth[32001];

int n, m;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		++depth[b];
	}

	set<int> Stk;

	for (int i = n; i > 0; --i)
	{
		if(depth[i] == 0)
			Stk.insert(i);
	}

	while (!Stk.empty())
	{
		int cur = *Stk.begin(); Stk.erase(Stk.begin());
		cout << cur << ' ';

		
		for (int nxt : adj[cur])
		{
			--depth[nxt];

			if (depth[nxt] == 0)
				Stk.insert(nxt);
		}

	}


	return 0;
}

