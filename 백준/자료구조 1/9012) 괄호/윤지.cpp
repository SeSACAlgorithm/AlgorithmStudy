#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int length;
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		string vfx;
		cin >> vfx;
		string answer = "YES";

		stack<char> tmp;

		for (int j = 0; j < vfx.length(); j++)
		{
			if (vfx[j] == '(')
			{
				tmp.push(vfx[j]);
			}
			else if (vfx[j] == ')' && !tmp.empty() && tmp.top() == '(')
			{
				tmp.pop();
			}
			else
			{
				if (tmp.empty())
				{
					answer = "NO";
					break;
				}

			}



		}

		if (!tmp.empty())
		{
			answer = "NO";
			//break;
		}

		cout << answer << endl;
	}
}