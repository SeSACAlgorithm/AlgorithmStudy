#include <iostream>
#include <string>
#include <queue>

using namespace std;

string RGB[102];
string RRB[102];
bool visRGB[102][102];
bool visRRB[102][102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> RGB[i];
		RRB[i] = RGB[i];

		for (int j = 0; j < RRB[i].size(); ++j)
		{
			if (RRB[i][j] == 'G')
				RRB[i][j] = 'R';
		}

	}

	queue<pair<int, int>> Q;


	int resRGB = 0;
	int resRRB = 0;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
   			if (visRGB[i][j]) continue;
			Q.push({ i,j });
			visRGB[i][j] = true;
			++resRGB;


			while (!Q.empty())
			{
				pair<int, int> cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (RGB[nx][ny] != RGB[cur.first][cur.second] || visRGB[nx][ny]) continue;
					visRGB[nx][ny] = true;
					Q.push({ nx,ny });
				}
			}
        }
    }
    

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visRRB[i][j]) continue;
			Q.push({ i,j });
			visRRB[i][j] = true;
			++resRRB;


			while (!Q.empty())
			{
				pair<int, int> cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (RRB[nx][ny] != RRB[cur.first][cur.second] || visRRB[nx][ny]) continue;
					visRRB[nx][ny] = true;
					Q.push({ nx,ny });
				}
			}
        }
    }

       
    cout << resRGB << ' ' << resRRB;

    return 0;
}

    
