#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    vector<int> nums(10, 0);
    for (int i = 0; i < 10; ++i)
        cin >> nums[i];

    set<int> check;
    for (int n : nums)
        check.insert(n % 42);

    cout << check.size();
}