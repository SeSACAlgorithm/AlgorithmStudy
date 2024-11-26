#include<iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int alpha[26] = { 0 };

	for (int i = 0; i < s.size(); i++)
	{
		alpha[(int)s[i] - 'a']++;
	}


	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";


	return 0;

}
