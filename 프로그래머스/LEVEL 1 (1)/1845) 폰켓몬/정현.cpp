#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    // 종류가 다 다르면 /2한 값이 answer
    int a = nums.size()/2;
    // 종류 중복이 있는지 확인하고 있으면 제거
    set<int> b;
    for(int i=0; i<nums.size(); i++){
        b.insert(nums[i]);
    }
    // a와 b 비교해서 작은게 답이여
    if(b.size() <=a)
        answer = b.size();
    else
        answer = a;
    
    return answer;
}
