#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;
	cin >> num;

	vector<string> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i];

	for (int idx = 0; idx < num; idx++)
	{
		string res = "YES";
		int count = 0;

		for (int i = 0; i < input[idx].size(); i++)
		{
			if (input[idx][i] == '(')
			{
				count++;
			}
			else
			{
				count--;
				if (count < 0)
				{
					res = "NO";
					break;
				}
			}
		}

		if (count > 0)
			res = "NO";

		cout << res << endl;
	}
}