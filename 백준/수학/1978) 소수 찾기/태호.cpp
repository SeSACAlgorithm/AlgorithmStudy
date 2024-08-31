#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool num[1001];
bool visit[1001];

int main()
{
	int n; cin >> n;

	vector<int> result(n);

	for(int i = 0; i < n; ++i)
		cin >> result[i];

	fill(visit + 1, visit + 1001, false);
	fill(num + 1, num + 1001, false);

	for (int i = 2; i < 1001; ++i)
	{
		if(visit[i]) continue;
		visit[i] = true;
		num[i] = true;

		for (int j = i + i; j < 1001; j += i)
			visit[j] = true;
	}

	int k = 0;

	for(int i = 0; i < result.size(); ++i)
	{
		if(num[result[i]])
			++k;
	}

	cout << k;

	return 0;
}
