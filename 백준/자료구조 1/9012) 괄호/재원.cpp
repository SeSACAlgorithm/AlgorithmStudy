#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void cal(string str)
{
	stack<int> s;
	bool bIsOk = true;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (!s.empty())
			{
				s.pop();

			}
			else
			{
				bIsOk = false;
				break;
			}
				
		}
	}
	if (!s.empty()||bIsOk==false)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
	}

}



int main() {
	
	vector<string> v; 
	int size;

	cin >> size;

	for (int i = 0; i < size; i++) //입력받기 
	{
		string input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < size; i++) //입력받기 
	{
		cal(v[i]);
	}


	

	return 0;
}
