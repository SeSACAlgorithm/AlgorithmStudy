#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> answer;

    for(int i = 0; i < nums.size(); ++i)
        answer.emplace(nums[i]);

    return min(nums.size() / 2, answer.size());
}
