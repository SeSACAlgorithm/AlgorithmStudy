#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, char>> p(1001);

int GetParent(int x)
{
	if(p[x].first == x) return x;
	return p[x].first = GetParent(p[x].first);
}

bool Merge(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);

	if(a == b) return false;
	if(p[a] == p[b]) --p[a].first;
	if(p[a] < p[b]) p[b].first = p[a].first;
	else p[a].first = p[b].first;
	return true;
}


int v, e;
int dist, a, b;

int main()
{
	cin >> v >> e;

	vector<tuple<int, int, int>> edge(e);

	for (int i = 1; i <= v; ++i)
	{
		char c; cin >> c;
		p[i].second = c;
		p[i].first = i;
	}

	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> dist;
		edge[i] = {dist, a, b};
	}


	sort(edge.begin(), edge.end());

	int cnt = 0;
	long long answer = 0;

	for (int i = 0; i < e; ++i)
	{
		tie(dist, a, b) = edge[i];

		if(p[a].second == p[b].second || !Merge(a, b)) continue;
		
		++cnt;
		answer += dist;
	}

	cnt = 0;

	for (int i = 1; i <= v; ++i)
	{
		if (p[i].first == i)
		{
			if (cnt == 1)
			{
				cout << -1;
				return 0;
			}

			++cnt;
		}
	}

	cout << answer;

}
