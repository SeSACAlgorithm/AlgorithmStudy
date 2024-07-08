#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    stack<pair<int, int>> Stk;
    vector<int> answer(n, -1);

    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        Stk.push({i, x});
    }

    pair<int, int> max = Stk.top();
    Stk.pop();

    stack<pair<int, int>> StkAnswer;

    while (!Stk.empty())
    {
        pair<int, int> cur = Stk.top();

        if(max.second <= cur.second)
        {
            max = cur;

            while (!StkAnswer.empty())
                StkAnswer.pop();
        }
        else
        {
            answer[cur.first] = max.second;

	        while (!StkAnswer.empty())
	        {
                pair<int,int> pre = StkAnswer.top();

                if(cur.second >= pre.second)
                {
                    StkAnswer.pop();
                }
                else
                {
                    answer[cur.first] = pre.second;
                    break;
                }
	        }

            StkAnswer.push(cur);
        }

        Stk.pop();
    }

    for(int i = 0; i < answer.size(); ++i)
		cout << answer[i] << ' ';


    return 0;
}
