//어차피 순서는 같으니까 
//s의 첫번째 인덱스 문자를 지정하여 t에서 찾기 
//t에서 찾으면 그다음 인덱스 찾기
//즉 t의 크기만큼 진행하는 for 문에서
//s의 0인덱스부터 일치하는걸 찾을수로 +1
//만약 for문이 끝나기전에 s의 마지막인덱스까지 찾으면 true

#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool checkstr(string s, string t)
{
	int idx = 0;

	for (int i = 0; i < t.size(); i++)
	{
		if (s[idx] == t[i])
		{
			idx++;
			if (idx == s.size())
			{
				return true;
			}
		}

	}
	return false;
}
int main()
{
	string s,t;
	vector<string>answer;
	while (cin >> s >>t )
	{
	

	
		if (checkstr(s, t) == true)
		{
			answer.push_back("Yes");
		}
		else
		{
			answer.push_back("No");
		}

	}



	for (auto a : answer)
		cout << a << endl;
}
