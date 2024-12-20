#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int>input;
	bool found = false;
	int t,sum;
	sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> t;
		sum += t;
		input.push_back(t);
	}

	
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (input[i] + input[j]) == 100)
			{
				input[i] = 0;
				input[j] = 0;
				found = true;
				break;
			}
		}
		if (found) break;
	}
	sort(input.begin(), input.end());

	for (int i = 2; i < 9; i++)
		cout << input[i] << endl;
}
