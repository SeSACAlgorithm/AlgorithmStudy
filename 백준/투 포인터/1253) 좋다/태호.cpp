#include <iostream>
#include <algorithm>

using namespace std;


int n, arr[2002]; 
bool IsGood[2002];



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int k = 0; k < n; ++k)
	{
		int i = 0, j = n - 1;

		while (i < j)
		{
			if (i == k) { ++i; continue; }
			if (j == k) { --j; continue; }

			int sum = arr[i] + arr[j];

			if (sum == arr[k])
			{
				IsGood[k] = true;
				break;
			}
			else if (sum < arr[k])
				++i;
			else
				--j;
		}
	}

	int answer = 0;

	for(int i = 0; i < n; ++i)
		if(IsGood[i])
			++answer;

	cout << answer;

	return 0;
}
