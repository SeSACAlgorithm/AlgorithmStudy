#include <queue>
#include <iostream>

using namespace std;

int dist[1002][1002];
int board[1002][1002];

int main()
{
	int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i)
	    for(int j = 0; j < m; ++j)
		    cin >> board[i][j];

    pair<int, int> dest;
    queue<pair<int, int>> Q;

    for (int i = 0; i < n; ++i)
    {
        bool bbreak = false;
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 2)
            {
                board[i][j] = 0;
                dest = {i, j};
                Q.push({i, j});
                bbreak = true;
            }
        }

        if(bbreak)
			break;
            
    }

    int dx[4] = {-1, 1, 0,0};
    int dy[4] = {0,0,-1,1};

	while (!Q.empty())
	{
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + cur.first;
            int ny = dy[dir] + cur.second;

            if (board[nx][ny] == 0 || dist[nx][ny] != 0) continue;
            if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;

            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
	}

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(board[i][j] == 1 && dist[i][j] == 0)
                dist[i][j] = -1;

	        cout << dist[i][j] << ' ';
        }

        cout << '\n';
    }

	return 0;
}
