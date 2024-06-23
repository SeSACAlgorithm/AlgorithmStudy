#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n; cin >> n;
    long long answer = 0;
    stack<char> Stk;

    int open = 0;

    for(int i = 0; i < n.size() - 1; ++i)
    {
        char cur = n[i];
    	  char nxt = n[i + 1];

        if(cur == '(')
        {
            if(cur != nxt)
            {
                answer += Stk.size();
                ++i;
            }
            else
            	Stk.push(n[i]);

        }
        else
        {
            ++answer;
            Stk.pop();
        }

    }

    cout << answer + Stk.size();


    return 0;
}
