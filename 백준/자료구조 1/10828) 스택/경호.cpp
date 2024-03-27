#include <stack>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int orders;
    cin >> orders;

    stack<int> stk;
    map<string, int> orderMap{ {"push", 1}, {"pop", 2 }, {"size", 3 } , {"empty", 4 } , {"top", 5 } };

    string query = "";
    int val = 0;
    int idx = 0;
    for (int i = 0; i < orders; i++)
    {
        cin >> query;
        idx = orderMap[query];
        switch (idx)
        {
        case 1:
            cin >> val;
            stk.push(val);
            break;
        case 2:
            if (stk.empty())
                cout << -1 << '\n';
            else
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
            break;
        case 3:
            cout << stk.size() << '\n';
            break;
        case 4:
            cout << stk.empty() << '\n';
            break;
        case 5:
            cout << (stk.empty() ? -1 : stk.top()) << '\n';
            break;
        }
    }
}