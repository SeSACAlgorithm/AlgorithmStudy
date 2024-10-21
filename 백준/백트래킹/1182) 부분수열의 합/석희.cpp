#include <iostream>
#include <vector>

using namespace std;

int N, S;
int answer = 0;
int sum = 0;
vector<int> v_nums;

void Solve(int count, int index, int now)
{
    if(index == count && sum == S)
    {
        answer++;
        return;
    }

    for(int i = now; i < v_nums.size(); i++)
    {
        sum += v_nums[i];
        Solve(count, index + 1, i + 1);
        sum -= v_nums[i];
    }
}

int main(void)
{
    cin >> N >> S;

    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        v_nums.push_back(num);
    }

    for(int i = 1; i <= N; i++)
    {
        Solve(i, 0, 0);
    }
    cout << answer;
}