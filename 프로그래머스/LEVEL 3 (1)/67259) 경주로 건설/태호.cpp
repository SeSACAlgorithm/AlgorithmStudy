#include <bits/stdc++.h>

using namespace std;

// N x N
// 1 x 1 

//  출발점(0, 0) 도착점(N-1, N-1)
// 중간에 끊기지 않도록 경주로를 건설
// 상,하,좌,우 인접한 두 빈 칸을 연결하여 건설 가능
// 상하 또는 좌우로 연결한 경주로 -> 직선 도로
// 직선 도로가 서로 직각으로 만나는 지점을 코너
// 직선 도로 -> 100, (1400(직각) + 400(코너) + 2000(코너 500)) 
// 코너 -> 500 
// 3차원 bfs 인듯? 상하좌우 + 2차원 배열
// 자동차가 오른쪽을 보는 상태에서 아래로 간다-> 코너

// 0    100 X   1500
// 100  700 800 900
// 200  X   1400 X    
// X   2100 1500 2100
//


const int MAX_INT = 30;
const int CONER = 600;
const int STRAIGHT = 100;

int dist[MAX_INT][MAX_INT][4];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) 
{
    int answer = numeric_limits<int>::max();
    
    int n = board.size();
    
    memset(dist, -1, sizeof(dist));
    
    queue<tuple<int, int, int>> que;
    que.push({0, 0, 0});
    que.push({0, 0, 1});
    
    dist[0][0][0] = 0;
    dist[0][0][1] = 0;
    
    while(!que.empty())
    {
        auto[x, y, carDist] = que.front();
        que.pop();
        
        int last_cost = dist[x][y][carDist];
        
        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny]) continue;
            
            int new_cost = last_cost + (dir == carDist ? STRAIGHT : CONER);
            
            if(dist[nx][ny][dir] == -1 || dist[nx][ny][dir] > new_cost)
            {
                dist[nx][ny][dir] = new_cost;
                que.push({nx, ny, dir});
            }
        }
    }
    
    --n;
    
    for(int dir = 0; dir < 4; ++dir)
    {
        if(dist[n][n][dir] != -1)
            answer = min(answer, dist[n][n][dir]);
        
        cout << dist[n][n][dir] << '\n';
    }
    
    return answer == numeric_limits<int>::max() ?  -1 : answer;
}
