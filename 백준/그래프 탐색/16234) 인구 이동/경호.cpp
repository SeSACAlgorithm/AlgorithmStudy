#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void BFS(vector<vector<int>>& nations, vector<vector<bool>>& visited, int by, int bx, int n, int left, int right)
{
	visited[by][bx] = true;

	vector<int> deltaX{ 0, 1, 0, -1 };
	vector<int> deltaY{ -1, 0, 1, 0 };

	queue<pair<int, int>> que;
	que.emplace(by, bx);

	int sum = 0;
	stack<pair<int, int>> stk; // 같은 연합 좌표 저장용 스택
	// BFS
	while(false == que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		stk.emplace(y, x);
		que.pop();
		sum += nations[y][x];

		for (int i = 0; i < deltaX.size(); ++i)
		{
			int ny = y + deltaY[i];
			int nx = x + deltaX[i];
			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= n) continue;
			if (visited[ny][nx]) continue;

			int diff = abs(nations[y][x] - nations[ny][nx]);
			if (diff < left || diff > right) continue;

			visited[ny][nx] = true;
			que.emplace(ny, nx);
		}
	}

	if (stk.size() < 2)
		return;

	// 연합의 인구수를 평균값으로 조정
	int avg = sum / stk.size();
	while(false == stk.empty())
	{
		int y = stk.top().first;
		int x = stk.top().second;
		stk.pop();

		nations[y][x] = avg;
	}
}

int main()
{
	int n, left, right;
	cin >> n >> left >> right;

	vector<vector<int>> nations(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> nations[i][j];

	int date = 0;
	int total = n * n;
	while(true)
	{
		vector<vector<bool>> visited(n, vector<bool>(n));
		int count = 0;
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (visited[y][x]) continue;

				BFS(nations, visited, y, x, n, left, right);
				++count;
			}
			// 모든 칸을 일일히 방문했다면 더 이상 인구 이동이 불가능하므로 종료
			if (count == total) 
				break;
		}
		if (count == total)
			break;

		++date; // 날짜 카운팅
	}

	cout << date;
}