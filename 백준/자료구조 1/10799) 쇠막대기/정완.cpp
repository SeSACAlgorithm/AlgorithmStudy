#include <iostream>
#include <stack>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    string str;
    cin >> str;

    int cnt = 0;
    stack<int> stk;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(' && str[i+1] == ')')
        {
            cnt += stk.size();
            i++;
        }

        else if(str[i] == '(')
            stk.push(i);

        else if(str[i] == ')')
        {
            cnt++;
            stk.pop();
        }
    }

    cout << cnt;
}