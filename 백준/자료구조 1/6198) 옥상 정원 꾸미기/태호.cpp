#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, answer = 0; cin >> n;
    stack<int> Stk;

    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;

        while (!Stk.empty() && Stk.top() <= x)
				Stk.pop();

        answer += Stk.size();
        Stk.push(x);

    }

    cout << answer;

    return 0;
}
