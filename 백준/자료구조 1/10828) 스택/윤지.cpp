#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec_stack;
	int length;

	cin >> length;

	for (int i = 0; i < length; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int tmp;
			cin >> tmp;
			vec_stack.push_back(tmp);
		}
		else if (cmd == "size") {
			cout << vec_stack.size() << endl;
		}
		else if (cmd == "empty") {
			if (vec_stack.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (cmd == "pop") {
			if (vec_stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << vec_stack.back() << endl;
				vec_stack.pop_back();
			}
		}
		else if (cmd == "top") {
			if (vec_stack.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << vec_stack.back() << endl;
			}
		}
	}
}