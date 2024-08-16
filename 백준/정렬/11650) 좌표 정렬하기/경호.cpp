#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b) const
    {
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    int x, y;
    for(int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        pq.emplace(x, y);
    }

    while(false == pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }
}
