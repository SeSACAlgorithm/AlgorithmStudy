#include<iostream>
#include<set>
#include<string>

using namespace std;

int arrL[100002];
set<int> S[102];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; ++i)
    {
	    int p, l; cin >> p >> l;
        arrL[p] = l;
        S[l].insert(p);
    }

    int k; cin >> k;

    for(int i = 0; i < k; ++i)
    {
        string str; cin >> str;

        if(str == "add")
        {
	        int p, l; cin >> p >> l;
            arrL[p] = l;
            S[l].insert(p);
        }
        else if(str == "recommend")
        {
	        int x; cin >> x;

            if(x == 1)
            {
				for(int i = 100; i > 0; --i)
				{
					if(!S[i].empty())
					{
                        cout << *--S[i].end() << '\n';
                        break;
					}
				}

                
            }
            else if(x == -1)
            {
                for (int i = 1; i <= 100; ++i)
                {
                    if (!S[i].empty())
                    {
                        cout << *S[i].begin() << '\n';
                        break;
                    }
                }
            }
        }
        else if(str == "solved")
        {
            int p; cin >> p;
        	S[arrL[p]].erase(S[arrL[p]].find(p));
            arrL[p] = 0;

        }
    }
}
