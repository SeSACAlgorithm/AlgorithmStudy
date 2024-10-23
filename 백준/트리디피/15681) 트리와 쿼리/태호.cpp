#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, q, a, b;

vector<int> adj[100001];
int result[100001];
bool visited[100001];

int dfs(int cur)
{
	int num = 1;

	for (int nxt : adj[cur])
	{
		if(visited[nxt]) continue;
		visited[nxt] = true;

		num += dfs(nxt);
	}

	result[cur] = num;
	return num;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visited[r] = true;
	dfs(r);

	while (q--)
	{
		cin >> a;
		cout << result[a] << '\n';
	}

	return 0;
}
