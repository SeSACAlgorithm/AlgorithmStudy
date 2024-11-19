#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	vector<int>answer;
	priority_queue<int,vector<int>,greater<int>>q;
	int count,input;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> input;

		if (input == 0) // 큐에서 값 하나 빼기
		{
			if (q.empty())//큐가 비어있다면 그냥 0반환
			{
				answer.push_back(0);
			}
			else
			{
				answer.push_back(q.top());//제일위에값 answer 벡터에 넣고 하나 제거 
				q.pop();
			}
		}
		else
		{
			q.push(input);
		}
	}
	for (auto a : answer)
		cout << a << "\n";
	return 0;
}
