#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<pair<int, int>> edges[10001];
bool visited[10001];
int maxLeafnode = 0;
int maxDist = 0;

void dfs(int cur, int sum)
{
	visited[cur] = true;

	// 만약에 현재 저장된 값보다 크다면 넣어주자.
	if (maxDist < sum)
	{
		maxDist = sum;
		maxLeafnode = cur;
	}

	// 구한 간선들로 부터 리프 노드들을 찾아주자.
	for (auto [nxt, cost] : edges[cur])
	{
		if (!visited[nxt])
		{
			dfs(nxt, sum + cost);
		}
	}
}

void input()
{
	int a, b, c;

	cin >> n;

	// 간선을 모두 구해준다.
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dfs(1, 0);

	fill(visited + 1, visited + n + 1, false);
	maxDist = 0;

	dfs(maxLeafnode, 0);

	cout << maxDist;

	return 0;
}
