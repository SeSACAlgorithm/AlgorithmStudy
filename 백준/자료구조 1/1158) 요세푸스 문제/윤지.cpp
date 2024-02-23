
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int order;
	int index;
	cin >> order >> index;

	queue<int> que;
	vector<int> answer;

	for (int i = 0; i < order; i++)
	{
		que.push(i + 1);
	}

	while (!que.empty())
	{
		for (int j = 0; j < index; j++)
		{
			if (j == index - 1)
			{
				answer.push_back(que.front());
				que.pop();
			}
			else
			{
				que.push(que.front());
				que.pop();
			}
		}
	}

	cout << "<";
	for (int i = 0; i < answer.size(); i++)
	{
		if (i == answer.size() - 1)
		{
			cout << answer[i];
		}
		else
		{
			cout << answer[i] << ", ";
		}

	}



	cout << ">";

}

