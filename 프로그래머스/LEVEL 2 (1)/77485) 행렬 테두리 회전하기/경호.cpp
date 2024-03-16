#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> nums(rows, vector<int>(columns, 0));
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            nums[i][j] = i * columns + j + 1;
    
    vector<int> answer;
    
    vector<int> deltaY{ 0, 1, 0, -1 };
    vector<int> deltaX{ 1, 0, -1, 0 };
    for(vector<int> q : queries)
    {
        int minY = q[0] - 1;
        int maxY = q[2] - 1;
        int minX = q[1] - 1;
        int maxX = q[3] - 1;
        
        int curY = minY, curX = minX;
        int bef = nums[curY][curX];
        int minValue = 10001;
        int dir = 0;
        while(true)
        {
            int nextY = curY + deltaY[dir];
            int nextX = curX + deltaX[dir];
            
            if(bef < minValue)
                minValue = bef;
            
            int temp = nums[nextY][nextX];
            nums[nextY][nextX] = bef;
            bef = temp;
            
            curX = nextX;
            curY = nextY;
            if(dir == 0 && curX == maxX) dir++;
            else if(dir == 1 && curY == maxY) dir++;
            else if(dir == 2 && curX == minX) dir++;
            else if(dir == 3 && curY == minY) break;
        }
        answer.push_back(minValue);
    }
    
    return answer;
}