#include <iostream>

using namespace std;

string str;
char alpha[5] = { 'a', 'e', 'i', 'o', 'u' };

bool One()
{
	for(char c : str)
		for(int i = 0; i < 5; ++i)
			if(c == alpha[i])
				return true;

	return false;
}

bool Two()
{
	
	string str1;
	string str2;

	for (char c : str)
	{
		bool cond = false;

		for (int i = 0; i < 5; ++i)
		{
			if (c == alpha[i])
			{
				str1 += c;
				str2.clear();
				cond = true;
				break;
			}
		}

		if (!cond)
		{
			str2 += c;
			str1.clear();
		}

		if(str1.size() == 3 || str2.size() == 3)
			return false;
			
	}

	return true;
}

bool Three()
{
	char pre = '?';

	for (char c : str)
	{
		if (c == pre)
		{
			if ((pre == 'e' && c == 'e') || (pre == 'o' && c == 'o')) continue;
			return false;
		}

		pre = c;
	}

	return true;
}


int main()
{
	

	while (true)
	{
		 cin >> str;

		if(str == "end") break;


		cout << "<"  << str << ">" << " is ";
		One() && Two() && Three() ? cout << "acceptable.\n" : cout << "not acceptable.\n";
	}
	
}
