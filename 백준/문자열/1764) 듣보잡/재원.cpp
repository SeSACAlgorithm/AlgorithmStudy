// n m 각각 n개 m개 입력받고
//각자의 자리에서 겹치는 이름의 개수와 이름을 사전순으로 출력
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, M;
	string s;
	vector<string>answer;
	map<string, int>m;
	cin >> N >> M;
	for (int i = 0; i <  N; i++)
	{
		cin >> s;
		m[s]++;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if (m.find(s) != m.end())//존재한다면
		{
			answer.push_back(s);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size()<<endl;

	for (auto a : answer)
		cout << a << endl;
	return 0;
}
