#include "iostream"
#include "stack"

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    stack<int> stk;
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        cin >> m;
        if(m == 0)
        {
            ans -= stk.top();
            stk.pop();

        }

        else
        {
            ans += m;
            stk.push(m);
        }
    }

    cout << ans;
}