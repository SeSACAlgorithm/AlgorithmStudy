#include <iostream>
#include <queue>

using namespace std;



int main(void)
{
	queue<int>q;

	int count;
	cin >> count;


	for (int i = 0; i < count ; i++)
	{
		q.push(i + 1); //q를 순서대로 채우기
	}

	while (q.size()!=1)
	{
		q.pop();
		int t=q.front();
		q.pop();
		q.push(t);

	}

	cout << q.front();
	return 0;
}
