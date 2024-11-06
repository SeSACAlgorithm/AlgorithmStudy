#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
    
	vector<vector<int>> v(n, vector<int>(n, 0));

	pair<int, int> answer;
	int start_row = 0, end_row = n - 1;
	int start_col = 0, end_col = n - 1;
	int cnt = n * n + 1;

	while (start_row <= end_row && start_col <= end_col)
	{
		for (int i = start_row; i <= end_row; ++i)
			v[i][start_col] = --cnt;

		++start_col;

		for (int i = start_col; i <= end_col; ++i)
			v[end_row][i] = --cnt;

		--end_row;

		for (int i = end_row; i >= start_row; --i)
			v[i][end_col] = --cnt;

		--end_col;

		for (int i = end_col; i >= start_col; --i)
			v[start_row][i] = --cnt;

		++start_row;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << v[i][j] << ' ';

			if(k == v[i][j])
				answer = {i + 1, j + 1};
		}

		cout << '\n';
	}

	cout << answer.first << ' ' << answer.second;

	return 0;
}
