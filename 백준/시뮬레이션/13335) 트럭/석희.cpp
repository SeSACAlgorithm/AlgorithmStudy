#include <iostream>
#include <queue>

using namespace std;

int truck[1001];

int main(void)
{
    int n, w, L;    // 트럭의 수, 다리의 길이, 다리 최대 하중

    cin >> n >> w >> L;
    for(int i = 0; i < n; i++)
    {
        cin >> truck[i];
    }

    int time = 0;
    int index = 0;
    int truck_sum = 0;

    queue<int> q_in_bridge_truck;

    while(1)
    {
        if(index == n) 
        {
            time += w;
            break;
        }
        time++;

        // 트럭이 다리를 다 건넌 경우
        if(q_in_bridge_truck.size() == w)
        {
            truck_sum -= q_in_bridge_truck.front();
            q_in_bridge_truck.pop();
        }

        // 다리에 올라갈 수 있는 경우
        if(truck_sum + truck[index] <= L)
        {
            truck_sum += truck[index];
            q_in_bridge_truck.push(truck[index]);
            index++;
        }
        // 올라갈 수 없다면 0 넣어서 시간 계산
        else
        {
            q_in_bridge_truck.push(0);
        }
    }
    
    cout << time;
}