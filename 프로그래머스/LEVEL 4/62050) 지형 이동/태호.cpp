#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


int solution(vector<vector<int>> land, int height){
    int answer = 0;
    int n = land.size();

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    priority_queue<tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>> pq;

    pq.push({ 0, 0, 0 });

    while (!pq.empty())
    {
        auto [d, x, y] = pq.top();
        pq.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (d > height)
            answer += d;

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;

            int diff = abs(land[nx][ny] - land[x][y]);
            int cost = diff > height ? diff : 0; 

            pq.push({ cost, nx, ny });
        }

    }

    return answer;
}
