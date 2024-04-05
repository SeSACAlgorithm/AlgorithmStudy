#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int max;
	cin >> max;

	string s;
	cin >> s;

	vector<double> nums(max);
	for (int i = 0; i < max; i++)
		cin >> nums[i];

	stack<double> stk;
	double a = 0, b = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(isalpha(s[i]))
		{
			stk.push(nums[s[i] - 'A']);
		}
		else
		{
			b = stk.top(); stk.pop();
			a = stk.top(); stk.pop();

			switch(s[i])
			{
			case '+':
				stk.push(a + b);
				break;
			case '-':
				stk.push(a - b);
				break;
			case '*':
				stk.push(a * b);
				break;
			case '/':
				stk.push(a / b);
				break;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stk.top();
}