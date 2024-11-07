#include<iostream>
#include<stack>
using namespace std;


int main()
{
	int count;
	cin >> count;
	stack <int> s;
	int sum = 0;
	int t;
	for (int i = 0; i < count; i++)
	{
		cin >> t;
		if (t == 0)
		{
			s.pop();
		}
		else
		{
			s.push(t);
		}

	}
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		sum += s.top();
		s.pop();

	}
	sum += s.top();
	cout << sum;
	return 0;

}
