#include <iostream>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int count = 0;
    string input;
    for(int i = 0; i < N; ++i)
    {
        cin >> input;

        // 스택이 비어있거나 마지막에 추가한 문자가 현재 문자와 다르다면 스택에 추가
        // 같다면, 겹치지 않는 아치를 이루므로 제거
        stack<char> stk;
        for(const char& c : input)
        {
            if (stk.empty() || stk.top() != c)
                stk.push(c);
            else
                stk.pop();
        }
        // 스택이 비어있다면 모든 문자가 겹치지 않는 아치를 이루었으므로 카운팅
        if (stk.empty())
            ++count;
    }

    cout << count;
}