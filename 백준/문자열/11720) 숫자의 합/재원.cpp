#include<iostream>
using namespace std;

int main()
{
	int count;
	cin >> count;
	string input;
	int sum = 0;
	cin >> input;
	for (int i = 0; i < count; i++)
	{
		sum += input[i]-48;
	}

	
	cout << sum;
	return 0;
}
