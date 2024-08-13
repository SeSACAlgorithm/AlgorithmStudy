#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int count;
    vector<pair<long long, long long>> answer(N);
    for(int idx = 0; idx < N; ++idx)
    {
        cin >> count;

        char order;
        long long value;
        multiset<long long> dpq;
        for(int i = 0; i < count; ++i)
        {
            cin >> order >> value;
            if(order == 'I')
            {
                dpq.insert(value);
            }
            else
            {
                if (dpq.empty()) continue;

                auto it = value == 1 ? --dpq.end() : dpq.begin();
                dpq.erase(it);
            }
        }

        if(dpq.empty())
            answer[idx] = pair<long long, long long>{ -1, 1 };
        else
        {
            auto high = --dpq.end();
            auto low = dpq.begin();
            answer[idx] = pair<long long, long long>{ *high, *low };
        }
    }

    for(const pair<long long, long long> ans : answer)
    {
        if (ans.first < ans.second)
            cout << "EMPTY" << "\n";
        else
            cout << ans.first << " " << ans.second << "\n";
    }
}