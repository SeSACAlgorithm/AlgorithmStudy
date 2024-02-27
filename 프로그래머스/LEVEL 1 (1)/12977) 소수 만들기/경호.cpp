#include <vector>
#include <math.h>

using namespace std;

int solution(vector<int> nums) {
    vector<int> sums;
    for(int i = 0; i < nums.size(); i++)
        for(int j = i + 1; j < nums.size(); j++)
            for(int k = j + 1; k < nums.size(); k++)
                sums.emplace_back(nums[i] + nums[j] + nums[k]);

    // 소수 검사
    int count = 0;
    for(int n : sums)
    {
        int limit = sqrt(n);
        bool isPrime = true;
        for(int i = 2; i <= limit; i++)
        {
            if(n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            count++;
    }

    return count;
}