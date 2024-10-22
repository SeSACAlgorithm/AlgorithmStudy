#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 좌표 및 날짜 정보 저장용 구조체
struct point
{
    int x;
    int y;
    int z;
    int date;

    point() : x(0), y(0), z(0), date(0) {}
    point(int nx, int ny, int nz, int nd) : x(nx), y(ny), z(nz), date(nd) {}
};

int main()
{
    int M, N, H;
    cin >> M >> N >> H;

    int total = 0; // 전체 토마토 수
    int done = 0; // 완숙된 토마토 수

    vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M)));
    queue<point> que;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                cin >> box[i][j][k];

                if (box[i][j][k] != -1) ++total;
                if (box[i][j][k] == 1)
                {
                    ++done;
                    // 완숙된 토마토라면 큐에 추가 및 방문 체크
                    que.emplace(k, j, i, 0);
                    visited[i][j][k] = true;
                }
            }
        }
    }
    // 이미 모든 토마토가 완숙된 상태라면 0 출력 후 종료
    if(total == done)
    {
        cout << 0;
        return 0;
    }

    // 앞 뒤 좌 우 위 아래
    vector<int> dx{ 0, 0, -1, 1, 0, 0 };
    vector<int> dy{ 1, -1, 0, 0, 0, 0 };
    vector<int> dz{ 0, 0, 0, 0, -1, 1 };

    // BFS
    while(false == que.empty())
    {
        point cur = que.front();
        que.pop();

        for(int i = 0; i < dx.size(); ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];

            // 박스 영역을 벗어나면 스킵
            // 빈칸이라면 스킵
            // 이미 방문한 칸이라면 스킵
            if (nx < 0 || nx >= M) continue;
            if (ny < 0 || ny >= N) continue;
            if (nz < 0 || nz >= H) continue;
            if (box[nz][ny][nx] == -1) continue;
            if (visited[nz][ny][nx]) continue;

            // 인접한 토마토를 완숙
            // 모두 완숙시켰다면 현재 날짜 +1 출력 후 종료
            ++done;
            if(done == total)
            {
                cout << cur.date + 1;
                return 0;
            }
            // 방문 체크 및 큐에 추가
            visited[nz][ny][nx] = true;
            que.emplace(nx, ny, nz, cur.date + 1);
        }
    }

    // BFS가 끝날때까지 모두 완숙시키지 못했다면 -1 출력
    cout << -1;
}