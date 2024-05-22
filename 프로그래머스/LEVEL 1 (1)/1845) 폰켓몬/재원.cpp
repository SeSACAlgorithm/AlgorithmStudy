#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    
    //1.nums를 순서대로 정렬
    //2.최대로 나올수 있는 result 값은 nums 배열안의 최대 다른 종류의 수의 수, nums 최대 크기 /2  따라서 ,
    //3.정렬된 nums의 첫번째 index를 가지고 배열 전체 요소에 대해 검사 
    //4.만약 검사 index와 다른수가 나온다면 answer 값을 1 올리고 현재 검사 index를 현재 값으로 변경후 같은과정을 반복한다
    //5.반복 검사가 끝나면 그것이 결과 , 만약 answer값이 nums의 /2 보다 크다면 answer는 nums/2
    
    
    sort(nums.begin(), nums.end());
    
    int examine = nums[0];
    answer = 1;
    
    for(int i=0;i<nums.size();i++)
    {
        if(examine!=nums[i])
        {
            answer++;
            examine=nums[i];
        }
    }
    
    if (answer > nums.size() / 2) answer = nums.size() / 2;
    return answer;
}
