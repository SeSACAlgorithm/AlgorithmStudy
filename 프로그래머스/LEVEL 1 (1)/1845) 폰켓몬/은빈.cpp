#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int num = nums.size()/2; //가져갈 폰켓몬 수
    set<int> a;
    for(int i=0; i<nums.size(); i++)
    {
        a.insert(nums[i]);
    }
    if(a.size() <= num) answer = a.size();
    else answer = num;
    
    return answer;
}

int main(void)
{
    vector<int> nums = {3,1,2,3};
    cout << solution(nums);
}