#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, root, leaf = 0;

vector<int> adj[52];
int visited[52];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;

		if (a == -1)
		{
			root = i;
		}
		else
		{
			adj[a].push_back(i);
		}

	}

	cin >> a;

	if (root == a)
	{
		cout << 0;
		return 0;
	}

	visited[a] = true;

	queue<int> que;
	que.push(root);

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		visited[cur] = true;

		bool cond = false;

		for (int nxt : adj[cur])
		{
			if (visited[nxt]) continue;
			que.push(nxt);
			cond = true;
		}

		if(!cond)
			++leaf;
	}

	cout << leaf;


	return 0;
}
