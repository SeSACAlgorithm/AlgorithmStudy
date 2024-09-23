#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct state
{
    int y;
    int x;
    
    state() : y(0), x(0) {}
    state(int new_y, int new_x) : y(new_y), x(new_x) {}
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int straight = 100, corner = 500;
    int n = static_cast<int>(board.size());
    
    vector<vector<vector<int>>> cost_board(4, vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::max())));
    cost_board[0][0][0] = 0;
    cost_board[1][0][0] = 0;
    cost_board[2][0][0] = 0;
    cost_board[3][0][0] = 0;
    
    queue<state> que;
    que.emplace(0, 0);
    while(false == que.empty())
    {
        state cur = que.front();
        que.pop();
        if(cur.y == n - 1 && cur.x == n - 1)
            continue;
        
        // 상
        if(cur.y > 0 && board[cur.y - 1][cur.x] == 0)
        {
            int straight_cost = cost_board[0][cur.y][cur.x] + straight;
            int corner_cost = straight_cost + corner;
            bool movable = false;
            
            for(int i = 0; i < 4; ++i)
            {
                if(i == 0)
                {
                    if(straight_cost < cost_board[i][cur.y - 1][cur.x])
                    {
                        cost_board[i][cur.y - 1][cur.x] = straight_cost;
                        movable = true;
                    }
                }
                else
                {
                    if(corner_cost < cost_board[i][cur.y - 1][cur.x])
                    {
                        cost_board[i][cur.y - 1][cur.x] = corner_cost;
                        movable = true;
                    }
                }
            }
            
            if(movable)
                que.emplace(cur.y - 1, cur.x);
        }
        // 우
        if(cur.x + 1 < n && board[cur.y][cur.x + 1] == 0)
        {
            int straight_cost = cost_board[1][cur.y][cur.x] + straight;
            int corner_cost = straight_cost + corner;
            bool movable = false;
            
            for(int i = 0; i < 4; ++i)
            {
                if(i == 1)
                {
                    if(straight_cost < cost_board[i][cur.y][cur.x + 1])
                    {
                        cost_board[i][cur.y][cur.x + 1] = straight_cost;
                        movable = true;
                    }
                }
                else
                {
                    if(corner_cost < cost_board[i][cur.y][cur.x + 1])
                    {
                        cost_board[i][cur.y][cur.x + 1] = corner_cost;
                        movable = true;
                    }
                }
            }
            
            if(movable)
                que.emplace(cur.y, cur.x + 1);
        }
        // 하
        if(cur.y + 1 < n && board[cur.y + 1][cur.x] == 0)
        {
            int straight_cost = cost_board[2][cur.y][cur.x] + straight;
            int corner_cost = straight_cost + corner;
            bool movable = false;
            
            for(int i = 0; i < 4; ++i)
            {
                if(i == 2)
                {
                    if(straight_cost < cost_board[i][cur.y + 1][cur.x])
                    {
                        cost_board[i][cur.y + 1][cur.x] = straight_cost;
                        movable = true;
                    }
                }
                else
                {
                    if(corner_cost < cost_board[i][cur.y + 1][cur.x])
                    {
                        cost_board[i][cur.y + 1][cur.x] = corner_cost;
                        movable = true;
                    }
                }
            }
            
            if(movable)
                que.emplace(cur.y + 1, cur.x);
        }
        // 좌
        if(cur.x > 0 && board[cur.y][cur.x - 1] == 0)
        {
            int straight_cost = cost_board[3][cur.y][cur.x] + straight;
            int corner_cost = straight_cost + corner;
            bool movable = false;
            
            for(int i = 0; i < 4; ++i)
            {
                if(i == 3)
                {
                    if(straight_cost < cost_board[i][cur.y][cur.x - 1])
                    {
                        cost_board[i][cur.y][cur.x - 1] = straight_cost;
                        movable = true;
                    }
                }
                else
                {
                    if(corner_cost < cost_board[i][cur.y][cur.x - 1])
                    {
                        cost_board[i][cur.y][cur.x - 1] = corner_cost;
                        movable = true;
                    }
                }
            }
            
            if(movable)
                que.emplace(cur.y, cur.x - 1);
        }
    }
    
    return min(cost_board[0][n - 1][n - 1], min(cost_board[1][n - 1][n - 1], min(cost_board[2][n - 1][n - 1], cost_board[3][n - 1][n - 1])));
}