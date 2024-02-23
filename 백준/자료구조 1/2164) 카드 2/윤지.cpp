
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	queue<int> que;

	for (int i = 0; i < num; i++)
	{
		que.push(i + 1);
	}

	int j = 1;

	while (que.size() != 1)
	{
		if (j % 2 != 0)
		{
			que.pop();
		}
		else
		{
			que.push(que.front());
			que.pop();
		}

		j++;
	}

	cout << que.front() << endl;

}

