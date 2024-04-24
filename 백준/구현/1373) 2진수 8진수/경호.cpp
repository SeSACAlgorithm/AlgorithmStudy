#include <map>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	map<string, string> conv{ {"0", "0"}, {"1", "1"},{"10", "2"},{"11", "3"} ,
								{"000", "0"}, {"001", "1"}, {"010", "2"}, {"011", "3"}, {"100", "4"}, {"101", "5"}, {"110", "6"}, {"111", "7"}};
	int remain = s.size() % 3;
	string answer = remain > 0 ? conv[s.substr(0, remain)] : "";

	int len = 3;
	for(int i = remain; i < s.size(); i += 3)
	{
		answer.append(conv[s.substr(i, len)]);
	}

	cout << answer;
}