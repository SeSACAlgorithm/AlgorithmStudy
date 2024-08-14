#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {    
    queue<pair<int, int>> q_num;
    priority_queue<int> pq_priority;

    for(int i = 0; i < priorities.size(); i++)
    {
        pq_priority.push(priorities[i]);
        q_num.push({i, priorities[i]});
    }

    int answer = 1;
    while(!q_num.empty())
    {
        int index = q_num.front().first;
        int priority = q_num.front().second;
        q_num.pop();

        if(pq_priority.top() == priority) 
        {
            if(index == location) return answer;

            pq_priority.pop();
            answer++;
        }

        else q_num.push({index, priority});
    }

    return answer;
}