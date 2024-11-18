#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int N;
vector<int> v;

int main()
{
    cin >> N;

    for(int i =0; i<N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.rbegin(), v.rend());

    ll ans = 0;

    for(int i=0; i<N; i++)
        if(v[i] - i > 0)        // 팁이 음수가 아닌 경우 
            ans += v[i] - i;    // v[i] - ((i + 1) - 1) => v[i] - i

    cout << ans;
}