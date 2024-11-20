//이미 입력받은 단어는 한번더 나오면 안된다 
#include<iostream>
#include<map>
using namespace std;

bool checkgroupword(string s)
{
	map<char, int>m;
	char previousword=s[0];
	for (int i = 0; i < s.size(); i++)
	{

		if (previousword != s[i]) //이전단어랑 다른 새로운 단어가 나왔는데
		{
			if (m.find(s[i]) != m.end()) //map에 이미 기록까지 되있다 
			{
				return false;
			}
		}
		m[s[i]]++;
		previousword = s[i];
	}

	return true; //반복이 끝나도 문제가 없으면 true
}


int main()
{
	int count,answer;
	cin >> count;
	answer = 0;

	string s;
	for (int i = 0; i < count; i++)
	{
		cin >> s;
		if (checkgroupword(s) == true)
			answer++;
	}


	cout << answer;
	return 0;

}
