#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> que;
    int temp = 0;
    for(int i = 0; i < progresses.size(); i++)
    {
        temp = 100 - progresses[i];
        temp = temp % speeds[i] > 0 ? temp / speeds[i] + 1 : temp / speeds[i];
        que.push(temp);
    }
    
    int curDay = que.front();
    int count = 1;
    que.pop();
    while(false == que.empty())
    {
        temp = que.front();
        que.pop();
        
        if(curDay < temp)
        {
            answer.push_back(count);
            curDay = temp;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}