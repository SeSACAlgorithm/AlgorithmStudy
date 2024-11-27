#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    NXN 크기 동굴
    [0][0] -> [N-1][N-1]  이동

    도둑루피가 있다면 소지금만큼 읽게됨
    최소로 건너편까지 이동

    5 3 3 2 7
    */

    int n;
    int board[130][130];

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    int cnt = 0;

    while (true)
    {
        cin >> n;

        vector<vector<int>>dist(n, vector<int>(n, 1e9));

        if(n == 0)
            break;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> board[i][j];

        dist[0][0] = board[0][0];

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({board[0][0], 0, 0});

        while (!pq.empty())
        {
            auto[d, x, y] = pq.top();
            pq.pop();
            
            if(dist[x][y] != d) continue;

            for (int dir = 0; dir < 4; ++dir)
            {
                int nx = dx[dir] + x;
                int ny = dy[dir] + y;

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (dist[nx][ny] > dist[x][y] + board[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + board[nx][ny];
                    pq.push({ dist[nx][ny], nx, ny });
                }
            }
        }

        cout << "Problem " << ++cnt <<": " << dist[n - 1][n - 1] << '\n';
    }

    return 0;
}
