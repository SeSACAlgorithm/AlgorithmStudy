#include <iostream>

using namespace std;

bool solve(string s, string t)
{
    int index = 0;
    int s_len = s.size();
    int t_len = t.size();

    for (int i = 0; i < t_len; i++)
    {
        if (index == s_len) break;
        if (t[i] == s[index]) index++;
    }

    return index == s_len;
}

int main(void)
{
    string s, t;
    bool answer;

    while(cin >> s >> t)
    {
        bool answer = solve(s, t);
        cout << (answer ? "Yes" : "No") << "\n";

    }
}