#include<iostream>

using namespace std;

bool isPrime(int x)
{
	if (x == 1)
		return false;
	int i = 2;
	while (i<x)
	{
		if (x % i == 0)
			return false;
		i++;
	}

	return true;
}

int main()
{

	int count,answer,input;
	answer = 0;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> input;
		if (isPrime(input) == true)
			answer++;
	}

	cout << answer;

	return 0;

}
