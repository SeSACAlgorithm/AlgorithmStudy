#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
set<int> nums;      // 중복 숫자 제거 (같은 수를 여러번 골라도 되니까)
vector<int> temp;

void Input()
{
    int num;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        nums.insert(num);
    }
}

void Solve(int index)
{
    if(index == M)
    {
        for(int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(auto i = nums.begin(); i != nums.end(); i++)
    {
        if(index != 0 && temp[index-1] > *i) continue;      // 비내림차순만 해야함
        temp.push_back(*i);
        Solve(index+1);
        temp.pop_back();
    }
}

int main(void)
{
    Input();
    Solve(0);
}