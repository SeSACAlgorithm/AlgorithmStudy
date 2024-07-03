#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2, 0));
    for(int i = 0; i < n; ++i)
        cin >> nums[i][0] >> nums[i][1];

    int big = 0, small = 0;
    for(int i = 0; i < n; ++i)
    {
        small = min(nums[i][0], nums[i][1]);
        big = max(nums[i][0], nums[i][1]);
        cout << lcm(big, small) << endl;
    }
}