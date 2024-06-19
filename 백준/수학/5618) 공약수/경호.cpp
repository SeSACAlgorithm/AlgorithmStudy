#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> answer;
    int limit = *min_element(nums.begin(), nums.end());
    for(int i = 1; i <= limit; ++i)
    {
        bool cd = true;
        for(int num : nums)
        {
            if (num % i > 0)
            {
                cd = false;
                break;
            }
        }
        if (cd) answer.emplace_back(i);
    }

    for (int ans : answer)
        cout << ans << endl;
}