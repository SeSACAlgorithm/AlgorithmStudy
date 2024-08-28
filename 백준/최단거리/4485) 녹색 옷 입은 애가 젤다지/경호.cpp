#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 좌표 및 비용 저장용 구조체
struct block_data
{
    int y;
    int x;
    int cost;

    block_data() : y(0), x(0), cost(0) {}
    block_data(int Y, int X, int c) : y(Y), x(X), cost(c) {}

    bool operator()(block_data a, block_data b) const
    {
        return a.cost > b.cost;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> answer;
    // 시계 방향
    vector<int> delta_y{ -1, 0, 1, 0 };
    vector<int> delta_x{ 0, 1, 0, -1 };
    while(true)
    {
        int N;
        cin >> N;
        if (N == 0) break;

        // 순서대로 루피 정보, 방문 여부, 누적 비용 저장
        vector<vector<int>> road(N, vector<int>(N));
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        vector<vector<int>> values(N, vector<int>(N, numeric_limits<int>::max()));
        for(int i = 0; i < N; ++i)
	        for(int j = 0; j < N; ++j)
                cin >> road[i][j];

        // 우선순위 큐에 저장하여 가장 누적 비용이 적은 값부터 추적
        priority_queue<block_data, vector<block_data>, block_data> que;
        que.emplace(0, 0, road[0][0]);
        values[0][0] = road[0][0];
        while(false == que.empty())
        {
            block_data cur = que.top();
            que.pop();
            // 목표 도달 시 answer에 누적된 비용을 추가하고 break
            if (cur.y == N - 1 && cur.x == N - 1)
            {
                answer.push_back(cur.cost);
                break;
            }

            visited[cur.y][cur.x] = true;
            for(int i = 0; i < 4; ++i)
            {
                int ny = cur.y + delta_y[i];
                int nx = cur.x + delta_x[i];
                // 다음 좌표가 범위를 벗어나면 스킵
                // 이미 방문한 곳이라면 스킵
                // 다음 좌표에 저장된 누적 비용이 현재 비용 + 다음 좌표의 비용보다 작다면 스킵
                if (ny < 0 || ny >= N) continue;
                if (nx < 0 || nx >= N) continue;
                if (visited[ny][nx]) continue;
                if(values[ny][nx] < cur.cost + road[ny][nx]) continue;
                // 조건을 모두 클리어했다면 큐에 추가
                que.emplace(ny, nx, cur.cost + road[ny][nx]);
            }
        }
    }

    // 정답 출력
    for(int i = 0; i < answer.size(); ++i)
        cout << "Problem " << i + 1 <<": " << answer[i] << "\n";
}