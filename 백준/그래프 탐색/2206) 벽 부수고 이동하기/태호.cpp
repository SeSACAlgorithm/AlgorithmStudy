#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

string board[1002];

/* 
	앞에 배열[2]에 대한 설명
	[0] -> 벽을 깨지 않은 상태의 bfs 활용
	[1] -> 벽을 한 번 깼을 때 상태의 bfs 활용 
*/
int dist[2][1002][1002];

struct coord
{
	int x, y;
	int dist;
};

queue<coord> que;

void Setting()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
		fill(dist[0][i], dist[0][i] + m, -1);
		fill(dist[1][i], dist[1][i] + m, -1);
	}

	que.push({ 0, 0, 0 });
	dist[0][0][0] = 0;
	board[0][0] = '2';
}

void Answer()
{
	if (n == 1 && m == 1)
	{
		cout << 1;
		return;
	}

	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = dx[dir] + cur.x;
			int ny = dy[dir] + cur.y;

			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			if (nx == m - 1 && ny == n - 1)
			{
				cout << dist[cur.dist][cur.y][cur.x] + 2;
				return;
			}

			// 앞에 가로막고 있는 것이 벽이라면?
			if (board[ny][nx] == '1')
			{
				// 현재 queue에서 벽을 뚫은 적이 없다면?
				// 이미 지나간 흔적이 없다면?
				if (!cur.dist && dist[1][ny][nx] == -1)
				{
					que.push({ nx, ny, 1 });
					dist[1][ny][nx] = dist[cur.dist][cur.y][cur.x] + 1;
				}
			}

			// 앞에 가로막고 있는 것이 없다면?
			// 지나간 흔적이 없다면?
			else if (board[ny][nx] == '0' && dist[cur.dist][ny][nx] == -1)
			{
				dist[cur.dist][ny][nx] = dist[cur.dist][cur.y][cur.x] + 1;
				que.push({ nx, ny, cur.dist });
			}

		}
	}

	cout << -1;
}

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	Setting();
	Answer();

	return 0;
}
