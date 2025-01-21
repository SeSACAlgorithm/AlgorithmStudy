#include<iostream>
#include<queue>
using namespace std;

struct compare {
	bool operator()(int o1, int o2)
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);

		if (first_abs == second_abs)
		{
			return o1 > o2;
		}
		else
		{
			return first_abs > second_abs;
		}
	}
};


int main()
{
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int,vector<int>,compare> q;

	int count,input;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> input;

		if (input == 0)
		{
			if (q.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
		{
			q.push(input);
		}
	}


}
