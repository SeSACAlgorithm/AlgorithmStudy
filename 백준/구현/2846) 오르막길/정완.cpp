#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    int ans = 0;
    int cur = 0;
    for(int i=0; i<n-1; i++)
    {
        if(v[i+1] > v[i])
            cur += v[i+1] - v[i];

        else
            cur = 0;
        
        ans = max(ans, cur);
    }

    cout << ans;
}

int main(void)
{
    solve();
    return 0;
}