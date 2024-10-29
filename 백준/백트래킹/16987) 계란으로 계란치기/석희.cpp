// 문제 분석
/*
    계란 내구도 -= 상대 계란 무개
    0이하 => 계란 깨짐
    계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어감

    최대한 많은 계란을 깨기
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int answer = 0;
vector<pair<int, int>> vEggs;           // 내구도, 무게

void Solve(int index)
{
    if(index >= N)
    {
        int count = 0;
        for(int i = 0; i < N; i++)
        {
            if(vEggs[i].first <= 0) count++;
        }
        answer = max(answer, count);
        return;
    }

    // 내구도가 0이하인 계란이라면
    if(vEggs[index].first <= 0) 
    {
        Solve(index + 1);
        return;
    }

    bool check = false;
    for(int i = 0; i < N; i++)
    {
        // 같은 계란이거나 이미 내구도가 0이하라면
        if(i == index || vEggs[i].first <= 0) continue;
        
        vEggs[i].first -= vEggs[index].second;
        vEggs[index].first -= vEggs[i].second;
        check = true;

        Solve(index + 1);

        vEggs[i].first += vEggs[index].second;
        vEggs[index].first += vEggs[i].second;  
    }

    // 모두 깨져있다면
    if(!check) Solve(N);
}

int main(void)
{
    int eggDurability, eggWeight;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> eggDurability >> eggWeight;
        vEggs.push_back({eggDurability, eggWeight});
    }
    
    Solve(0);
    cout << answer;
}