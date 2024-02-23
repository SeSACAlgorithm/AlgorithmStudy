#include <bits/stdc++.h>

using namespace std;

stack<int> s;
string command;
int N;

void push()
{
    int X;
    cin >> X;
    s.push(X);
}

void pop()
{
    if (s.empty())
        cout << -1 << '\n';
    
    else
    {
        cout << s.top() << '\n';
        s.pop();
    }
}

void size()
{
    cout << s.size() << '\n';
}

void empty()
{
    s.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
}

void top()
{
    s.empty() ? cout << -1 << '\n' : cout << s.top() << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "push")
            push();

        else if (command == "pop")
            pop();
        else if (command == "size")
            size();
        else if (command == "empty")
            empty();
        else if (command == "top")
            top();
    }

    return 0;
}
