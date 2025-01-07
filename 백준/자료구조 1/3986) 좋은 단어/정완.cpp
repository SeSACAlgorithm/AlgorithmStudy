#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cnt = 0;

    string input;

    for(int i=0; i<n; i++)
    {
        cin >> input;

        stack<char> stk;

        for(auto a : input)
        {
            if( stk.empty() || stk.top() != a)   // 스택이 비었거나, 마지막 입력값이 현재 문자랑 다를 경우
                stk.push(a);

            else
                stk.pop();
        }

        if(stk.empty())
            cnt++;
    }

    cout << cnt;
}