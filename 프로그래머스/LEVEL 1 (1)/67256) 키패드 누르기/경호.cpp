#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    map<int, map<int, int>> dist;
    dist.emplace(2, map<int, int>());
    dist.emplace(5, map<int, int>());
    dist.emplace(8, map<int, int>());
    dist.emplace(0, map<int, int>());
    for(int i = 1, j = 1; i < 13; i += 3, j++)
    {
        dist[2][i] = j;
        dist[2][i + 1] = j - 1;
        dist[2][i + 2] = j;
    }
    for(int i = 1, j = 1; i < 13; i += 3, j++)
    {
        dist[5][i] = abs(2 - j) + 1;
        dist[5][i + 1] = abs(2 - j);
        dist[5][i + 2] = abs(2 - j) + 1;
    }
    for(int i = 1, j = 1; i < 13; i += 3, j++)
    {
        dist[8][i] = abs(3 - j) + 1;
        dist[8][i + 1] = abs(3 - j);
        dist[8][i + 2] = abs(3 - j) + 1;
    }
    for(int i = 1, j = 4; i < 13; i += 3, j--)
    {
        dist[11][i] = j;
        dist[11][i + 1] = j - 1;
        dist[11][i + 2] = j;
    }
    
    int curL = 10, curR = 12;
    for(int num : numbers)
    {
        if(num == 0)
            num = 11;
        
        if(num % 3 == 1)
        {
            answer.append("L");
            curL = num;
        } 
        else if(num % 3 == 0)
        {
            answer.append("R");
            curR = num;
        }  
        else
        {
            int l = dist[num][curL];
            int r = dist[num][curR];
            if(l < r)
            {
                answer.append("L");
                curL = num;
            }
            else if(l > r)
            {
                answer.append("R");
                curR = num;
            }
            else
            {
                if(hand[0] == 'l')
                {
                    answer.append("L");
                    curL = num;
                }
                else
                {
                    answer.append("R");
                    curR = num;
                }
            }
        }
    }
    return answer;
}