#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(const int& a, const int& b) const
	{
        return abs(a) == abs(b) ? a > b : abs(a) > abs(b);
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;
    int temp;
    for(int i = 0; i < N; ++i)
    {
        cin >> temp;

        if(temp != 0)
        {
            pq.push(temp);
            continue;
        }
            
        if (pq.empty())
            cout << 0 << "\n";
        else
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}