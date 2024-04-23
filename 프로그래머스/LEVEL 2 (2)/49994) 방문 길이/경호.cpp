#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    map<string, bool> check;
    map<char, int> horizontal{ {'U',0}, {'D',0}, {'L',-1}, {'R',1} };
    map<char, int> vertical{ {'U',1}, {'D',-1}, {'L',0}, {'R',0} };
    
    int curX = 0, curY = 0;
    int nextX = 0, nextY = 0;
    bool h_moved = false;
    for(int i = 0; i < dirs.size(); ++i)
    {
        nextX = curX + horizontal[dirs[i]];
        nextY = curY + vertical[dirs[i]];
        
        if(nextX < -5 || nextX > 5) continue;
        if(nextY < -5 || nextY > 5) continue;
        
        string tmp1 = to_string(curX) + to_string(curY) + to_string(nextX) + to_string(nextY);
        string tmp2 = to_string(nextX) + to_string(nextY) + to_string(curX) + to_string(curY);
        curX = nextX, curY = nextY;
        if(false == check[tmp1])
        {
            check[tmp1] = true;
            check[tmp2] = true;
            ++answer;
        }
    }
    
    return answer;
}