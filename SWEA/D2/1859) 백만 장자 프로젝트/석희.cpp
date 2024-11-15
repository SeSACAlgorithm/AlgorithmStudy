#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nums[1000000];

void Input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}

void Solve()
{
    long long answer = 0;
    int maxPrice = 0;

    for(int i = n-1; i >= 0; i--)
    {
        maxPrice = max(maxPrice, nums[i]);
        answer = answer + (maxPrice - nums[i]);
    }

    cout << answer << "\n";
}

int main(void)
{
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++)
    {
        cout << "#" << test_case << " ";
        Input();
        Solve();
    }
}