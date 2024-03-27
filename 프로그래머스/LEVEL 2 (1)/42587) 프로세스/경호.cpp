#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> flags{0, 1, 2, 4, 8, 16, 32, 64, 128, 256};
    vector<int> uppers{0, 510, 508, 504, 496, 480, 448, 384, 256, 0};
    vector<int> count(10, 0);
    
    int flag = 0;
    for(int& num : priorities)
    {
        if(count[num] == 0)
            flag += flags[num];
        
        ++count[num];
    }
    
    queue<int> que;
    for(int& num : priorities)
        que.push(num);
    
    int temp = 0;
    while(false == que.empty())
    {
        temp = que.front();
        que.pop();
        // 더 큰 priority가 없다면 실행
        if((flag & uppers[temp]) == 0)
        {
            answer++;
            
            --count[temp];
            if(count[temp] == 0)
                flag -= flags[temp];
            
            if(location == 0) break;
        }
        else
            que.push(temp);
        
        location = (location - 1 + que.size()) % que.size();
    }
    
    return answer;
}