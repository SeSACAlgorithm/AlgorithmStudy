#include <iostream>
#include <cmath>
#include <utility>

using namespace std;


int n, m, r;
int dist, a, b;

int answer[105][105];
int location[105];

int main()
{
	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i)
	{
		fill(answer[i], answer[i] + n + 1, 16);
		cin >> location[i];
		answer[i][i] = 0;
	}

	for (int i = 0; i < r; ++i)
	{
		cin >> a >> b >> dist;
		answer[a][b] = min(answer[a][b], dist);
		answer[b][a] = min(answer[b][a], dist);
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (answer[i][j] > answer[i][k] + answer[k][j])
				{
					answer[i][j] = answer[i][k] + answer[k][j];
				}
			}
		}
	}

	long long res = 0;

	for (int i = 1; i <= n; ++i)
	{
		long long cnt = 0;

		for(int j = 1; j <=n; ++j)
			if(m >= answer[i][j])
				cnt += location[j];

		res = max(res, cnt);
	}

	cout << res;
}
