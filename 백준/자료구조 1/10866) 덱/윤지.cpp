#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	list<int> deq;

	int line;
	cin >> line;


	for (int i = 0; i < line; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push_front")
		{
			int tmp;
			cin >> tmp;

			deq.push_front(tmp);
		}
		else if (cmd == "push_back")
		{
			int tmp;
			cin >> tmp;

			deq.push_back(tmp);
		}
		else if (cmd == "pop_front")
		{
			cout << (deq.empty() ? -1 : deq.front()) << endl;
			if (!deq.empty()) deq.pop_front();
		}
		else if (cmd == "pop_back")
		{
			cout << (deq.empty() ? -1 : deq.back()) << endl;
			if (!deq.empty()) deq.pop_back();
		}
		else if (cmd == "size")
		{
			cout << deq.size() << endl;
		}
		else if (cmd == "empty")
		{
			cout << (deq.empty() ? 1 : 0) << endl;
		}
		else if (cmd == "front")
		{
			cout << (deq.empty() ? -1 : deq.front()) << endl;
		}
		else if (cmd == "back")
		{
			cout << (deq.empty() ? -1 : deq.back()) << endl;
		}
	}



}

