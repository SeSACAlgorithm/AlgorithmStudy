#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size()/2;

    set<int>numSet(nums.begin(), nums.end());
    
    if(answer < numSet.size())
        return answer;
    
    else
        return numSet.size();
}
