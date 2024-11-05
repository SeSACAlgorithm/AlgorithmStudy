#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
int craftTime[501];
int depth[501];

int main()
{
	int n; cin >> n;
	vector<int> result(n + 1);

	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		cin >> craftTime[i];

		int k; cin >> k;

		while (k != -1)
		{
			adj[k].push_back(i);
			++depth[i];
			cin >> k;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (depth[i] == 0) {
			q.push(i);
			result[i] = craftTime[i];
		}
	}


	while (!q.empty())
	{
		int elem = q.front();
		q.pop();

		for (auto& cur : adj[elem])
		{
			--depth[cur];

			result[cur] = max(result[cur], result[elem] + craftTime[cur]);

			if (!depth[cur])
			{
				craftTime[cur] += craftTime[elem];
				q.push(cur);
			}
		}
	}

	for (int i = 1; i < result.size(); ++i)
		cout << result[i] << '\n';

	return 0;
}
