#include<iostream>
#include<deque>
using namespace std;

typedef pair<int, int> Node;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count,size,now;
	deque<Node>dq;

	cin >> count >> size;


	for (int i = 0; i < count; i++)
	{
		cin >> now;

		while (dq.size()&&dq.back().first>now)
		{
			dq.pop_back();
		}
		dq.push_back(Node(now,i));
	
		if (dq.front().second <= i - size)
		{
			dq.pop_front();
		}
		cout << dq.front().first<<' ';
	}




	return 0;
}
