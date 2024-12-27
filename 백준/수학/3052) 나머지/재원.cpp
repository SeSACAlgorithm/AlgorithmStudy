#include<iostream>
#include<map>
using namespace std;

int main()
{
	int input,count;
	count = 0;
	map<int,int>remain;
	for (int i = 0; i < 10; i++)
	{
		cin >> input;
		remain[input % 42]++;
	}

	for (auto a : remain)
	{
		count++;
	}
	cout << count;
}
