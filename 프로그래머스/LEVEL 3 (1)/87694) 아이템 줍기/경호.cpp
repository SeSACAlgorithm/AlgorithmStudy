#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct locData
{
    int y;
    int x;
    int len;
    
    locData() : y(0), x(0), len(0) {}
    locData(int newY, int newX, int newLen) : y(newY), x(newX), len(newLen) {}
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    int maxVal = 0;
    for(const vector<int>& rec : rectangle)
        maxVal = max(*max_element(rec.begin(), rec.end()), maxVal);

    // 좌표값을 그대로 사용할 경우 인접한 도로의 연결 경로를 확실하게 알 수 없음
    // 좌표에 2를 곱해서 사용하고, 마지막 계산값을 2로 나누는 방식으로 해결
    int maxLen = (maxVal + 1) * 2;
    vector<vector<int>> area(maxLen, vector<int>(maxLen, 0));
    characterY *= 2;
    characterX *= 2;
    itemY *= 2;
    itemX *= 2;
    
    // 사각형 별 테두리 칠하기
    for(const vector<int>& rec : rectangle)
    {
        int startY = rec[1] * 2, endY = rec[3] * 2;
        int startX = rec[0] * 2, endX = rec[2] * 2;
        for(int x = startX; x <= endX; ++x)
        {
            area[startY][x] = 1;
            area[endY][x] = 1;
        }
        for(int y = startY; y <= endY; ++y)
        {
            area[y][startX] = 1;
            area[y][endX] = 1;
        }
    }
    
    // 사각형 안쪽 지우기
    for(const vector<int>& rec : rectangle)
    {
        int startY = rec[1] * 2, endY = rec[3] * 2;
        int startX = rec[0] * 2, endX = rec[2] * 2;
        for(int x = startX + 1; x < endX; ++x)
        {
            area[startY + 1][x] = 0;
            area[endY - 1][x] = 0;
        }
        for(int y = startY + 1; y < endY; ++y)
        {
            area[y][startX + 1] = 0;
            area[y][endX - 1] = 0;
        }
    }
    
    // BFS
    vector<int> deltaX{ 0, 1, 0, -1 }; // 시계 방향
    vector<int> deltaY{ -1, 0, 1, 0 }; // 시계 방향
    vector<vector<bool>> visited(maxLen, vector<bool>(maxLen, false));
    
    queue<locData> paths;
    paths.push(locData(characterY, characterX, 0));
    visited[characterY][characterX] = true;
    while(false == paths.empty())
    {
        locData cur = paths.front();
        paths.pop();
        
        // 도착했다면 종료
        if(cur.y == itemY && cur.x == itemX)
        {
            answer = cur.len / 2;
            break;
        }
        
        // 탐색(시계방향)
        for(int i = 0; i < 4; ++i)
        {
            locData next(cur.y + deltaY[i], cur.x + deltaX[i], cur.len + 1);
            if(next.x < 0 || next.x >= maxLen) continue;
            if(next.y < 0 || next.y >= maxLen) continue;
            if(area[next.y][next.x] == 0) continue;
            if(visited[next.y][next.x]) continue;
            
            visited[next.y][next.x] = true;
            paths.push(next);
        }
    }
    
    return answer;
}