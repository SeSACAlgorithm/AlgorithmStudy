#include <bits/stdc++.h>

using namespace std;

deque<int> d;
int X;
int N;
string command;
void push_front()
{
    cin >> X;
    d.push_front(X);
}

void push_back()
{
    cin >> X;
    d.push_back(X);
}

void pop_front()
{
    if (d.empty())
        cout << -1 << '\n';
    else
    {
        cout << d.front() << '\n';
        d.pop_front();
    }
}

void pop_back()
{
    if (d.empty())
        cout << -1 << '\n';

    else
    {
        cout << d.back() << '\n';
        d.pop_back();
    }
}

void size()
{
    cout << d.size() << '\n';
}

void empty()
{
    d.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
}

void front()
{
    d.empty() ? cout << -1 << '\n' : cout << d.front() << '\n';
}

void back()
{
    d.empty() ? cout << -1 << '\n' : cout << d.back() << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> command;

        if (command == "push_front")
            push_front();

        else if (command == "push_back")
            push_back();

        else if (command == "pop_front")
            pop_front();

        else if (command == "pop_back")
            pop_back();

        else if (command == "size")
            size();

        else if (command == "empty")
            empty();

        else if (command == "front")
            front();

        else if (command == "back")
            back();
    }
    return 0;
}
