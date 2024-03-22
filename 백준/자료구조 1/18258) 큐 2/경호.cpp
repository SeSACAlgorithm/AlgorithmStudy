#include <queue>
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

    queue<int> que;
    map<string, int> orderMap{ {"push", 1}, {"pop", 2 }, {"size", 3 } , {"empty", 4 } , {"front", 5 }, {"back", 6 } };

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
            que.push(val);
            break;
        case 2:
            if (que.empty())
                cout << -1 << '\n';
            else
            {
                cout << que.front() << '\n';
                que.pop();
            }
            break;
        case 3:
            cout << que.size() << '\n';
            break;
        case 4:
            cout << que.empty() << '\n';
            break;
        case 5:
            cout << (que.empty() ? -1 : que.front()) << '\n';
            break;
        case 6:
            cout << (que.empty() ? -1 : que.back()) << '\n';
            break;
        }
    }
}