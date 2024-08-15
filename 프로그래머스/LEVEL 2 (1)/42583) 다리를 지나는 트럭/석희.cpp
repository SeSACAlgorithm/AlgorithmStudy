// 출력 - 모든 트럭이 건너려면 걸리는 최소 시간
// 입력 - bridge_length : 다리에 오를 수 있는 최대 트럭 개수
//      - weight : 다리에 오를 수 있는 최대 무게
//      - truck_weights : 트럭들의 무게

// 선입선출 - queue

#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int truck_sum = 0;
    int index = 0;

    queue<int> q_bridge_truck;

    while (1)
    {
        if (index == truck_weights.size())
            return (answer += bridge_length);

        answer++;
        
        // 차가 다리를 다 건넌 경우
        if (q_bridge_truck.size() == bridge_length)
        {
            truck_sum -= q_bridge_truck.front();
            q_bridge_truck.pop();
        }

        // 다리에 올라갈 수 있는 경우
        if (truck_sum + truck_weights[index] <= weight)
        {
            truck_sum += truck_weights[index];
            q_bridge_truck.push(truck_weights[index]);
            index++;
        }
        else  // 올라갈 수 없다면 
        {
           // 0 넣어서 시간 계산
            q_bridge_truck.push(0);
        }
    }

    return answer;
}