#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;
vector<char> result;
int seq = 1;

int main() 
{
	int n; cin >> n;
	
	while (n--)
	{
		int num; cin >> num;

		while (seq <= num)
		{
			stk.push(seq++);
			result.push_back('+');
		}

		if (stk.top() == num)
		{
			stk.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for(char c : result)
		cout << c << '\n';

	return 0;
}
