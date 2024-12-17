#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int inputs, sum,size,max;
	cin >> size >> sum;
	vector<int>v;
	max = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> inputs;
		v.push_back(inputs);
	}

	for (int a = 0; a < size-2; a++)
	{
		for (int b = a+1; b < size; b++)
		{
			for (int c = b+1; c < size; c++)
			{
				if (v[a] + v[b] + v[c] > sum)
				{
					continue;
				}
				else
				{
					if (max < v[a] + v[b] + v[c])
						max = v[a] + v[b] + v[c];
				}
			}
		}
	}
	cout << max;
}
