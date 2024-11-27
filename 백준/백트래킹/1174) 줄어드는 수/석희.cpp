#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int digit = 0;

vector<long long> vNums;
vector<long long> vAnswer;

int nums[10] = {9,8,7,6,5,4,3,2,1,0};

void FindDecreaseNum(int index, int now)
{
    if(index == digit) 
    {
        long long temp = 0;
        for(int i = 0; i < vNums.size(); i++)
        {
            temp += vNums[i];
            if(i != vNums.size() - 1) temp = temp * 10; 
        }
        vAnswer.push_back(temp);
        return;
    }

    for(int i = now; i <= 9; i++)
    {
        vNums.push_back(nums[i]);
        FindDecreaseNum(index + 1, i + 1);
        vNums.pop_back();
    }
}

void Solve()
{
    cin >> N;
    if(N > 1023) {cout << -1; return;}
    for(int i = 1; i <= 10; i++)
    {
        digit = i;
        FindDecreaseNum(0, 0);
    }
    sort(vAnswer.begin(), vAnswer.end());
    cout << vAnswer[N-1];
}

int main(void)
{
    Solve();
}