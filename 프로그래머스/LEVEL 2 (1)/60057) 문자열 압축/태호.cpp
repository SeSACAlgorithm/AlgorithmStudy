#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 2100000000;

    for (int i = 1; i <= s.size(); ++i)
    {
        stack<pair<string ,int>> ST;
        ST.push({ s.substr(0, i), 0});

        for (int j = 0; j < s.size(); j += i)
        {
            string str = s.substr(j, i);

            auto& cur = ST.top();

            if (cur.first == str)
                ++cur.second;

            else
                ST.push({ str, 1 });
        }

        int mx = 0;

        while (!ST.empty())
        {
            auto cur = ST.top(); ST.pop();
            int k = 0;

            if(cur.second != 1)
            {
                while (cur.second)
                {
                    cur.second /= 10;
                    ++k;
                }
            }

            mx += cur.first.size() + k;

        }

        answer = min(answer, mx);

    }

    return answer;
}
