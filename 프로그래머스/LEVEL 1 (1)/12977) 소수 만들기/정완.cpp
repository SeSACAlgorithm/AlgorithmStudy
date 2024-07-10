#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int ans = 0;
    int sum = 0;
    
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                bool chk = false;
                sum = nums[i] + nums[j] + nums[k];
                
                for(int l=2; l*l<=sum; l++)
                {
                    if(sum % l == 0)
                    {
                        chk = true;
                        break;
                    }
                }
                 if (chk == false)
                     ans++;
            }
        }
    }
    return ans;
}
