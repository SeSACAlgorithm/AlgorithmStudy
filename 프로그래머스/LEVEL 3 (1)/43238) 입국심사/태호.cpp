#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int k;


bool solve(ll x, const vector<int>& times)
{
    ll cnt = 0;

    for(int i = 0; i < times.size(); ++i)
        cnt += x / times[i];

    return cnt < k;
}

ll solution(int n, vector<int> times) {
    ll answer = 0;
    k = n;
    ll lo = 0, hi = (ll)n  * 1000000000;

    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if(solve(mid, times)) lo = mid;
        else hi = mid;
    }

    return hi;
}
