#include "iostream"

using namespace std;

int N;

int solve()
{
    int ans = 0;

    while (N >=0)
    {
        if(N % 5 == 0)
        {
            ans += N/5;
            return ans;
        }
        ans++;
        N -= 3;
    }
    return -1;
}

int main()
{
    cin >> N;
    cout << solve();
}