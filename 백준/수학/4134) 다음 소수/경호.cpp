#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<long long> res(n, 0);
    int offset = 0;
    for (int i = 0; i < n; )
    {
        if(nums[i] < 2)
        {
            res[i] = 2;
            ++i;
            continue;
        }

        long long target = nums[i] + offset;
        int limit = sqrt(target);
        bool is_prime = true;
        for(int j = 2; j <= limit; ++j)
        {
	        if(target % j == 0)
	        {
                is_prime = false;
                break;
	        }
        }

        if (is_prime)
        {
            res[i] = target;
            offset = 0;
            ++i;
        }
        else
            ++offset;
    }

    for (long long r : res)
        cout << r << endl;
}