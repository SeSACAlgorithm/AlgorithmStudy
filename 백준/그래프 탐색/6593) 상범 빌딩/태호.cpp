#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n, m, l;

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

string board[32][32];
int dist[32][32][32];
struct coord { int x, y, z; };

queue<coord> que;

void Setting()
{
	for (int k = 0; k < l; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> board[k][i];
			fill(dist[k][i], dist[k][i] + m, -1);

			for (int j = 0; j < m; ++j)
			{
				if (board[k][i][j] == 'S')
				{
					dist[k][i][j] = 0;
					que.push({j , i, k});
				}
			}
			
		}
	}

}

void Answer()
{
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();

		for (int dir = 0; dir < 6; ++dir)
		{
			int nx = dx[dir] + cur.x;
			int ny = dy[dir] + cur.y;
			int nz = dz[dir] + cur.z;

			if(nx < 0 || ny < 0 || nz < 0) continue;
			if(nx >= m || ny >= n || nz >= l) continue;
			if (board[nz][ny][nx] == 'E')
			{
				cout << "Escaped in " << dist[cur.z][cur.y][cur.x] + 1 << " minute(s).\n";
				return;
			}
			
			if(board[nz][ny][nx] == '#' || dist[nz][ny][nx] != -1) continue;

			dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
			que.push({nx, ny, nz});
		}
	}

	cout << "Trapped!\n";
}

void Clear()
{
	while (!que.empty())
		que.pop();
}

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	while (true)
	{
		cin >> l >> n >> m;

		if(!l && !n && !m)
			break;

		Setting();
		Answer();
		Clear();
	}

	return 0;
}
