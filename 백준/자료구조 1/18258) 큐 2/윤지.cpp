#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int line;
    cin >> line;

    queue<int> que;
    
    for (int i = 0; i < line; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int tmp;
            cin >> tmp;
            que.push(tmp);
        }
        else if (cmd == "pop") {
            if (que.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << que.front() << '\n';
                que.pop();
            }
            
        }
        else if (cmd == "size") {
            cout << que.size() << '\n';

        }
        else if (cmd =="empty") {
            if (que.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "front") {
            if (que.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << que.front() << '\n';
            }
        }
        else if (cmd == "back") {
            if(que.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << que.back() << '\n';
            }
        }

    }

    return 0;
}

