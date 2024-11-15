#include<iostream>
#include<map>
using namespace std;

int main()
{
	int Ssize, Inputsize;
	cin >> Ssize >> Inputsize;
	map<string, int>m;
	string s;
	int answer = 0;
	for (int i = 0; i < Ssize; i++)
	{
		cin >> s;
		m[s] = 1;
	}
	for (int i = 0; i < Inputsize; i++)
	{
		cin >> s;
		if (m[s]==1)
			answer++;
	}

	cout << answer;
		

	return 0;

}
