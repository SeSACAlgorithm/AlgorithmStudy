#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K;
vector<int> nums;
vector<int> temp;

int digit = 0;
string answer;

void FindDigit()
{
    int num = N;
    while(num > 0)
    {
        num = num / 10;
        digit++;
    }
}

void Input()
{
    cin >> N >> K;

    int num;
    for(int i = 0; i < K; i++)
    {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(), less<int>());
}

void FindNums(int index, int limit)
{
    if(index == limit)
    {
        string answerTemp;
        for(int i = 0; i < temp.size(); i++)
        {
            answerTemp.push_back(temp[i] + '0');
        }
        if(!answerTemp.empty() && stoi(answerTemp) <= N) answer = answerTemp;
        return;
    }

    for(int i = 0; i < K; i++)
    {
        temp.push_back(nums[i]);
        FindNums(index+1, limit);
        temp.pop_back();
    }
}

int main(void)
{
    Input();
    FindDigit();

    for(int i = 1; i <= digit; i++)
    {
        FindNums(0, i);
    }
    cout << answer;
}