#include<iostream>

using namespace std;

int main()
{
	int n,max;
	cin >> n;
	int* arr = new int[n];
	max = 0;
	

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	int i = 1;
	while (i <= max)
	{
		if (n == 2)
		{
			if (arr[0] % i == 0 && arr[1] % i == 0)
				cout << i << endl;
		}
		else
		{
			if (arr[0] % i == 0 && arr[1] % i == 0&& arr[2] % i == 0)
				cout << i << endl;
		}
		

		i++;
	}

	return 0;

}
