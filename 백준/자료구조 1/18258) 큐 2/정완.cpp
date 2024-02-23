#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> que;
	int N;

	string str;
	int number;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> number;
			que.push(number);
		}

		if (str == "pop")
		{
			if (!que.empty())
			{
				cout << que.front() << '\n';
				que.pop();
			}

			else if (que.empty())
			{
				cout << -1 << '\n';
			}
		}

		if (str == "size")
		{
			cout << que.size() << '\n';
		}

		if (str == "empty")
		{
			if (que.empty())
			{
				cout << 1 << '\n';
			}

			else if (!que.empty())
			{
				cout << 0 << '\n';
			}
		}

		if (str == "front")
		{
			if(!que.empty())
			{
			cout << que.front() << '\n';
			}

			else if(que.empty())
			{
				cout<<-1<<'\n';
			}
		}

		if (str == "back")
		{
			if (!que.empty())
			{
				cout << que.back() << '\n';
			}

			else if (que.empty())
			{
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}
