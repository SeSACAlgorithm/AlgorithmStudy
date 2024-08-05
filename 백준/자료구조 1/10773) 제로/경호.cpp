#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;

    stack<int> stk;
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        if (num > 0)
            stk.emplace(num);
        else
            stk.pop();
    }

    uint32_t sum = 0;
    while (false == stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }

    cout << sum;
}