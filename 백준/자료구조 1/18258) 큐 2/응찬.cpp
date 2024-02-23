#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    queue<int> q;
    int X;
    int N;
    string input;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if (input == "push")
        {
            cin >> X;
            q.push(X);
        }

        else if (input == "pop")
        {
            if (q.empty())
            {
                cout << -1 <<'\n';
            }

            else
            {
                cout << q.front() <<'\n';
                q.pop();
            }
        }

        else if (input == "size")
        {
            cout << q.size() <<'\n';
        }

        else if (input == "empty")
        {
            if (q.empty())
            {
                cout << 1 <<'\n';
            }

            else
                cout << 0 <<'\n';
        }

        else if (input == "front")
        {
            if (q.empty())
            {
                cout << -1 <<'\n';
            }
            else
                cout << q.front() <<'\n';
        }

        else if (input == "back")
        {
            if (q.empty())
            {
                cout << -1<<'\n';
            }

            else
                cout << q.back() <<'\n';
        }
    }

    return 0;
}
