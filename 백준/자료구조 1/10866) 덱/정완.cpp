#include "iostream"
#include "deque"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;
	int N;

	string str;
	int num;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}

		else if (str == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}

		else if (str == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}

			else
			{
				cout << -1 << endl;
			}
		}

		else if (str == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}

			else
			{
				cout << -1 << endl;
			}
		}

		else if (str == "size")
		{
			cout << dq.size() << endl;
		}

		else if (str == "empty")
		{
			if (dq.empty())
			{
				cout << 1 << endl;
			}
			if (!dq.empty())
			{
				cout << 0 << endl;
			}
		}

		else if (str == "front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << endl;
			}

			else if (dq.empty())
			{
				cout << -1 << endl;
			}
		}

		else if (str == "back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << endl;
			}

			else if (dq.empty())
			{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
