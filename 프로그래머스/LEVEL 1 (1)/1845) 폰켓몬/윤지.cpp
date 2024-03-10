#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int visited[200010] = {0};
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(answer == nums.size()/2)
        {
            break;
        }
        
        if(visited[nums[i]] == 0)
        {
            visited[nums[i]] = 1;
            answer++;
        }
    }
    return answer;
}