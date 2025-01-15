#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int start, end, money;
};

int n;
int dp[16];
vector<node> v;

void Input()
{
    cin >> n;

    int s, e, m;
    for(int i = 1; i <= n; i++)
    {   
        cin >> e >> m;
        v.push_back({i, i + e - 1, m});
    }
}

void Solve()
{
    if(v[0].end <= n) dp[0] = v[0].money;
    int answer = dp[0];
    for(int i = 1; i < n; i++)
    {
        if(v[i].end > n) continue;

        dp[i] = v[i].money;
        for(int j = 0; j < i; j++)
        {
            if(v[i].start > v[j].end) dp[i] = max(dp[i], dp[j] + v[i].money);
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;
}

int main(void)
{
    Input();
    Solve();
}
