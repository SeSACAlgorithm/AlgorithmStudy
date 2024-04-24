#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int target;
	cin >> target;
	int targetY = 0, targetX = 0;

	vector<vector<int>> res(N, vector<int>(N, 0));

	int curY = N / 2, curX = N / 2;
	int num = 1;
	int limit = N * N;

	int dir = 0;
	int cur_count = 1;
	int dir_count = 1;
	vector<int> deltaY{ -1, 0, 1, 0 };
	vector<int> deltaX{ 0, 1, 0, -1 };

	int nextY = 0, nextX = 0;
	while(num <= limit)
	{
		res[curY][curX] = num;
		if(num == target)
		{
			targetY = curY + 1;
			targetX = curX + 1;
		}

		nextY = curY + deltaY[dir], nextX = curX + deltaX[dir];
		--cur_count;
		
		if(cur_count == 0)
		{
			dir = (dir + 1) % 4;
			if ((dir & 1) == 0)
				++dir_count;
			cur_count = dir_count;
		}
		curY = nextY, curX = nextX;
		++num;
	}

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << res[i].back() << endl;
	}
	cout << targetY << " " << targetX;
}