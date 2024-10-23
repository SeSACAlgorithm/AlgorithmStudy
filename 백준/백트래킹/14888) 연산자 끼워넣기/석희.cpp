#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[12];
int oper[4];

int min_answer = 1000000001;
int max_answer = -1000000001;

void Input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    for(int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }
}

// 연산자 몇개썼는지, 합
void Solve(int index,int sum)
{
    if(index == N)
    {
        min_answer = min(min_answer, sum);
        max_answer = max(max_answer, sum);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        if(oper[i] == 0) continue;
        oper[i]--;
        if(i == 0) Solve(index + 1, sum + nums[index]);
        else if(i == 1) Solve(index + 1, sum - nums[index]);
        else if(i == 2) Solve(index + 1, sum * nums[index]);
        else if(i == 3) Solve(index + 1, sum / nums[index]);
        oper[i]++;
    }
}

int main(void)
{
    Input();
    Solve(1, nums[0]);

    cout << max_answer << "\n";
    cout << min_answer << "\n";
}