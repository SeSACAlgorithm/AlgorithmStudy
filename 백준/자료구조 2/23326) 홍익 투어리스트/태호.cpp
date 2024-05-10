#include<iostream>
#include<set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    set<int> S;

    int current = 0;

    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        if(x == 1) S.insert(i);
    }
	    

    while (q--)
    {
	    int x; cin >> x;

        if(x == 1)
        {
            cin >> x;
            --x;

            if(S.end() != S.find(x))
				S.erase(x);
            else 
				S.insert(x);

        }
        else if(x == 2)
        {
	        cin >> x;
            current = (current + x) % n;
        }
        else if(x == 3)
        {
            if(S.empty())
                cout << -1 << '\n';
            else
            {
                auto iter = S.lower_bound(current);
                if(iter != S.end())
                    cout << *iter - current << '\n';
                else
                    cout << *S.begin() + n - current << '\n';  // 올바른 거리 계산
            }
        }
    }
}
