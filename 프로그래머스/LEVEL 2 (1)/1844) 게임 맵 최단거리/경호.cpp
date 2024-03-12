#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int x = 0;
    int y = 0;
    int value = 1;
    
    Point() {}
    Point(int X, int Y, int Val) : x(X), y(Y), value(Val) {}
};

int solution(vector<vector<int>> maps)
{
    int answer = 10001;
    
    queue<Point> que;
    int xLimit = maps[0].size();
    int yLimit = maps.size();
    
    vector<vector<bool>> visited(yLimit, vector<bool>(xLimit, false));
    vector<int> deltaX{ 0, 1, 0, -1 };
    vector<int> deltaY{ -1, 0, 1, 0 };
    
    que.push(Point(0, 0, 1));
    visited[0][0] = true;
    Point curPoint;
    while(false == que.empty())
    {
        curPoint = que.front();
        que.pop();
        
        // 목적지인 경우
        if(curPoint.x == xLimit - 1 && curPoint.y == yLimit - 1)
        {
            if(answer > curPoint.value)
                answer = curPoint.value;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nextX = curPoint.x + deltaX[i];
            int nextY = curPoint.y + deltaY[i];
            
            // 범위를 벗어나거나 벽이거나 이미 방문한 곳이라면 스킵
            if(nextX < 0 || nextX >= xLimit) continue;
            if(nextY < 0 || nextY >= yLimit) continue;
            if(maps[nextY][nextX] == 0) continue;
            if(visited[nextY][nextX]) continue;
            // 방문
            que.push(Point(nextX, nextY, curPoint.value + 1));
            visited[nextY][nextX] = true;
        }
    }
    return answer == 10001 ? -1 : answer;
}