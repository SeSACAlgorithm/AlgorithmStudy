#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>answer;
	int count;
	cin >> count;
	int a, b, t,origin;
	for (int i = 0; i < count; i++)
	{
		t = 1;
		cin >> a >> b;
		origin = a;
		while (a % b != 0)
		{
			a=origin;
			a = a * t;
			t++;
		
		}
		answer.push_back(a);
	}

	for (int i = 0; i < count; i++)
	{
		cout << answer[i] << endl;
	}
	return 0;

}
