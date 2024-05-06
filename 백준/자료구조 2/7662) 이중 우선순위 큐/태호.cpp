#include<iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    while (n--)
    {
        multiset<int> ms;
        int k; cin >> k;

        for(int i = 0; i < k; ++i)
        {
	        char c; int x; cin >> c; cin >> x;

            if(c == 'I')
            {
                ms.insert(x);
            }
            else
            {
				if(!ms.empty())
				{
                    if (x == 1)
                    {
                        ms.erase(--ms.end());
                    }
                    else if(x == -1)
                    {
                        ms.erase(ms.begin());
                    }
                    else
                    {
                        auto elem = ms.find(x);

                        if(elem != ms.end())
							ms.erase(elem);
                    }
				}
            }
        }


        ms.empty()  
    		? cout << "EMPTY" << '\n'
    		: cout << *--ms.end() << ' ' << *ms.begin() << '\n';
    }

}
