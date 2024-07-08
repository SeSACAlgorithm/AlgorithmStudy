#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
int depth[1001];


int n, m;

int main()
{

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int x, a, pre = 0;
		cin >> x;
		
		if (x == 0) continue;

		cin >> pre;

		for (int j = 0; j < x - 1; ++j)
		{
			cin >> a;

			adj[pre].push_back(a);
			++depth[a];

			pre = a;
		}
		
	}

	queue<int> Q;

	for (int i = 1; i <= n; ++i)
	{
		if (depth[i] == 0)
			Q.push(i);
	}

	vector<int> result;

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		result.push_back(cur);

		for (int nxt : adj[cur])
		{
			--depth[nxt];

			if (depth[nxt] == 0)
			{
				Q.push(nxt);
			}
		}
	}

	if (result.size() != n)
    {
		cout << "0";
        return 0;
    }


	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << '\n';


	return 0;
}

