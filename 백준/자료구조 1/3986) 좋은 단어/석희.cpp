#include <iostream>
#include <stack>

using namespace std;

bool solve(string str)
{
    stack<char> s;

    for(int i = 0; i < str.size(); i++)
    {
        if(!s.empty())
        {
            if(str[i] == s.top()) 
            {
                s.pop();
                continue;
            }
        }
        s.push(str[i]);
    }

    if(s.empty()) return true;
    else return false;
}

int main(void)
{
    int N;
    cin >> N;

    string str;
    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        if(solve(str)) answer++;
    }
    cout << answer;
}