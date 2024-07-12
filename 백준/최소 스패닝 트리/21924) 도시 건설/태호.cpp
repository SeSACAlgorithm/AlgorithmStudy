#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(100001, -1);

int GetParent(int x)
{
	if(p[x] < 0) return x;
	return p[x] = GetParent(p[x]);
}


bool Merge(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);

	if(a == b) return false;
	if(p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;

}


int v, e, dist, a, b;


int main()
{
	long long answer = 0;
	long long sum = 0;

	cin >> v >> e;
	vector<tuple<int, int, int>> edge(e);

	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> dist;
		edge[i] = {dist, a, b};
		sum += dist;
	}


	sort(edge.begin(), edge.end());

	int cnt = 0;

	for (int i = 0; i < e; ++i)
	{
		tie(dist, a, b) = edge[i];

		if(!Merge(a,b)) continue;

		answer += dist;
		++cnt;

		if(cnt == v - 1) break;
	}

	cnt = 0;

	for (int i = 1; i <= v; ++i)
	{
		if (p[i] < 0)
		{
			if (cnt == 1)
			{
				cout << -1;
				return 0;
			}

			++cnt;
		}

	}


	cout << sum - answer;
}
