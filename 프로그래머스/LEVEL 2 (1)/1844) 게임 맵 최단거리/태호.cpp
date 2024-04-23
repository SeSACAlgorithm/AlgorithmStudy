#include<vector>
#include<queue>

using namespace std;


bool myMap[101][101];
int dist[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int solution(vector<vector<int>> maps)
{
    int answer = 0;

    int x = maps.size(); 
    int y = maps[0].size();

    for(int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            myMap[i][j] = maps[i][j];
    
    dist[0][0] = 1;

    queue<pair<int, int>> Q;
    Q.push({0, 0});

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if(dist[x -1][y - 1]) break;

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if(dist[nx][ny] || !myMap[nx][ny]) continue;

            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
        
    }

    if(!dist[x - 1][y - 1])
        return -1;

    return dist[x - 1][y - 1];
}
