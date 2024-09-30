#include <queue>
#include <vector>

using namespace std;

struct position
{
    int y1;
    int x1;
    int y2;
    int x2;
    int sec;
    
    position() : y1(0), x1(0), y2(0), x2(1), sec(0) {}
    position(int new_y1, int new_x1, int new_y2, int new_x2, int new_sec) 
            : y1(new_y1), x1(new_x1), y2(new_y2), x2(new_x2), sec(new_sec) {}
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = static_cast<int>(board.size());
    
    // 이동 방향 변화량(시계방향)
    vector<int> delta_y{ -1, 0, 1, 0 };
    vector<int> delta_x{ 0, 1, 0, -1 };
    
    // 방문 여부 체크용 벡터
    // 수직, 수평 방향 구분하기 위해 2개 사용
    vector<vector<bool>> h_visited(n, vector<bool>(n,false));
    vector<vector<bool>> v_visited(n, vector<bool>(n,false));
    
    queue<position> que;
    que.push(position());
    h_visited[0][0] = true;
    h_visited[0][1] = true;
    while(false == que.empty())
    {
        position cur = que.front();
        que.pop();
        // 목적지에 도착했다면 break
        if((cur.y1 == n - 1 && cur.x1 == n - 1) || (cur.y2 == n - 1 && cur.x2 == n - 1))
        {
            answer = cur.sec;
            break;
        }
        
        bool horizontal = cur.y1 == cur.y2;
        // 이동 체크
        for(int i = 0; i < 4; ++i)
        {
            int ny1 = cur.y1 + delta_y[i];
            int nx1 = cur.x1 + delta_x[i];
            int ny2 = cur.y2 + delta_y[i];
            int nx2 = cur.x2 + delta_x[i];
            
            if(ny1 >= 0 && ny1 < n && ny2 >= 0 && ny2 < n)
            {
                if(nx1 >= 0 && nx1 < n && nx2 >= 0 && nx2 < n)
                {
                    if(board[ny1][nx1] == 0 && board[ny2][nx2] == 0)
                    {
                        if(horizontal)
                        {
                            if(h_visited[ny1][nx1] == false || h_visited[ny2][nx2] == false)
                            {
                                que.emplace(ny1, nx1, ny2, nx2, cur.sec + 1);
                                h_visited[ny1][nx1] = true;
                                h_visited[ny2][nx2] = true;
                            }
                        }
                        else
                        {
                            if(v_visited[ny1][nx1] == false || v_visited[ny2][nx2] == false)
                            {
                                que.emplace(ny1, nx1, ny2, nx2, cur.sec + 1);
                                v_visited[ny1][nx1] = true;
                                v_visited[ny2][nx2] = true;
                            }
                        }
                    }
                }
            }              
        }
        
        // 회전 체크
        if(horizontal)
        {
            // 위로 회전 가능한가
            if(cur.y1 > 0 && board[cur.y1 - 1][cur.x1] == 0 && board[cur.y2 - 1][cur.x2] == 0)
            {
                // 왼쪽을 축으로 위로 회전
                if(false == v_visited[cur.y2 - 1][cur.x2 - 1])
                {
                    que.emplace(cur.y2 - 1, cur.x2 - 1, cur.y1, cur.x1, cur.sec + 1);
                    v_visited[cur.y2 - 1][cur.x2 - 1] = true;
                }
                // 오른쪽을 축으로 위로 회전
                if(false == v_visited[cur.y1 - 1][cur.x1 + 1])
                {
                    que.emplace(cur.y1 - 1, cur.x1 + 1, cur.y2, cur.x2, cur.sec + 1);
                    v_visited[cur.y1 - 1][cur.x1 + 1] = true;
                }
            }
            // 아래로 회전 가능한가
            if(cur.y1 + 1 < n && board[cur.y1 + 1][cur.x1] == 0 && board[cur.y2 + 1][cur.x2] == 0)
            {
                // 왼쪽을 축으로 아래로 회전
                if(false == v_visited[cur.y2 + 1][cur.x2 - 1])
                {
                    que.emplace(cur.y1, cur.x1, cur.y2 + 1, cur.x2 - 1, cur.sec + 1);
                    v_visited[cur.y2 + 1][cur.x2 - 1] = true;
                }
                // 오른쪽을 축으로 아래로 회전
                if(false == v_visited[cur.y1 + 1][cur.x1 + 1])
                {
                    que.emplace(cur.y2, cur.x2, cur.y1 + 1, cur.x1 + 1, cur.sec + 1);
                    v_visited[cur.y1 + 1][cur.x1 + 1] = true;
                }
            }
        }
        else 
        {
            // 왼쪽으로 회전 가능한가
            if(cur.x1 > 0 && board[cur.y1][cur.x1 - 1] == 0 && board[cur.y2][cur.x2 - 1] == 0)
            {
                // 위를 축으로 왼쪽으로 회전
                if(false == h_visited[cur.y2 - 1][cur.x2 - 1])
                {
                    que.emplace(cur.y2 - 1, cur.x2 - 1, cur.y1, cur.x1, cur.sec + 1);
                    h_visited[cur.y2 - 1][cur.x2 - 1] = true;
                }
                // 아래를 축으로 왼쪽으로 회전
                if(false == h_visited[cur.y1 + 1][cur.x1 - 1])
                {
                    que.emplace(cur.y1 + 1, cur.x1 - 1, cur.y2, cur.x2, cur.sec + 1);
                    h_visited[cur.y1 + 1][cur.x1 - 1] = true;
                }
            }
            // 오른쪽으로 회전 가능한가
            if(cur.x1 + 1 < n && board[cur.y1][cur.x1 + 1] == 0 && board[cur.y2][cur.x2 + 1] == 0)
            {
                // 위를 축으로 오른쪽으로 회전
                if(false == h_visited[cur.y2 - 1][cur.x2 + 1])
                {
                    que.emplace(cur.y1, cur.x1, cur.y2 - 1, cur.x2 + 1, cur.sec + 1);
                    h_visited[cur.y2 - 1][cur.x2 + 1] = true;
                }
                // 아래를 축으로 오른쪽으로 회전
                if(false == h_visited[cur.y1 + 1][cur.x1 + 1])
                {
                    que.emplace(cur.y2, cur.x2, cur.y1 + 1, cur.x1 + 1, cur.sec + 1);
                    h_visited[cur.y1 + 1][cur.x1 + 1] = true;
                }
            }
        }
    }
    
    return answer;
}