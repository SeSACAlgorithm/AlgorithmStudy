#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    int order;
    for(int i = 0; i < N; ++i)
    {
        cin >> order;
        if(order > 0)
            pq.push(order);
        else
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}