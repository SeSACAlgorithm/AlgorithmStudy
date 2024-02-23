#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> stack;      // 스택
	int n;                 // Input 개수

	string str;            // 명령어
	int number;            // push 숫자

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> number;
			stack.push(number);
		}

		if (str == "pop")
		{
			if (!stack.empty())
			{
				cout << stack.top() << endl;
				stack.pop();
			}

			else if (stack.empty())
			{
				cout << -1 << endl;
			}
		}

		if (str == "size")
		{
			cout << stack.size() << endl;
		}

		if (str == "empty")
		{
			if (stack.empty())
			{
				cout << 1 << endl;
			}

			else if (!stack.empty())
			{
				cout << 0 << endl;
			}
		}

		if (str == "top")
		{
			if (!stack.empty())
			{
				cout << stack.top() << endl;
			}

			else if (stack.empty())
			{
				cout << -1 << endl;
			}
		}
	}
}
