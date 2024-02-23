#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int num;
	cin >> num;

	queue<int> que;
	for (int i = 0; i < num; i++)
		que.push(i + 1);

	int last = 0;
	while (que.size() > 1)
	{
		que.pop();
		last = que.front();
		que.pop();
		que.push(last);
	}

	cout << que.front();
}