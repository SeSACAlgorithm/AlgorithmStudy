#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer(n);
    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        nums[i] = i + 1;
    
    vector<long long> factorials(n + 1);
    factorials[0] = 1;
    for(int i = 1; i <= n; ++i)
        factorials[i] = factorials[i - 1] * i;
        
    long long F, div;
    for(int idx = 0; idx < n; ++idx)
    {
        F = factorials[n - idx - 1];
        div = (k - 1) / F;
        
        answer[idx] = nums[div];
        nums.erase(nums.begin() + div);
        k = (k - 1) % F + 1;
    }
    
    return answer;
}