#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<char> codes;

    stack<int> nums;
    int cur = 0, last = 1;
    bool possible = true;

    for(int i = 0; i < N; ++i)
    {
        cin >> cur;
        if (false == possible)
            continue;

        for (last; last <= cur; ++last)
        {
            nums.push(last);
            codes.push_back('+');
        }

        if(nums.top() == cur)
        {
            nums.pop();
            codes.push_back('-');
        }
        else
            possible = false;
    }

    if (possible)
    {
        for (const char& code : codes)
            cout << code << "\n";
    }
    else
    {
        cout << "NO";
    }
}