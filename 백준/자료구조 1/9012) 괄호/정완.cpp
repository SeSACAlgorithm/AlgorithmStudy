#include "iostream"
#include "stack"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    for(int i=0; i<num; i++)
    {
        string brackets;
        cin >> brackets;

        stack<char> stk;
        string ans = "YES";

        for(int j=0; j<brackets.size(); j++)
        {
            if(brackets[j] == '(')
                stk.push(brackets[j]);

            if(brackets[j] == ')')
            {
                if(stk.empty())
                {
                    ans = "NO";
                    break;    
                }

                if(stk.top() == '(')
                    stk.pop();
            }
        }

        if(!stk.empty())
            ans = "NO";

        cout << ans << endl;
    }

}