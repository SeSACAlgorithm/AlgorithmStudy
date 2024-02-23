#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> sCollection;

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sCollection.insert(nums[i]);
    }
    answer = sCollection.size() < nums.size() / 2 ? sCollection.size() : nums.size() / 2;

    return answer;
}