#include <bits/stdc++.h>
using namespace std;

stack<int> sequence;
vector<char> answer;
int n;
int tmp;
int value = 1;

void push()
{
    answer.push_back('+');
    sequence.push(value);
    value++;
}

void pop()
{
    sequence.pop();
    answer.push_back('-');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        while (value <= tmp)
        {
            push();
        }

        if (tmp == sequence.top())
            pop();

        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }
}
