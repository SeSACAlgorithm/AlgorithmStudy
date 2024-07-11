#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(301, -1);


int GetParent(int x)
{
    if(p[x] < 0) return x;
    return p[x] = GetParent(p[x]);
}

bool Merge(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    if(a == b) return false;
    if(p[a] == p[b]) --p[a];
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}

int v, e, a, b, dist;
tuple<int, int, int> edge[90601];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> v;

    for (int i = 1; i <= v; ++i)
    {
        cin >> dist;
        edge[e++] = { dist, i, v + 1 };
    }

    for (int i = 1; i <= v; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            cin >> dist;
            if(i >= j) continue;
            edge[e++] = { dist, i, j};
        }
    }

    sort(edge, edge + e);

    int cnt = 0;
    long long answer = 0;

    for (int i = 0; i < e; ++i)
    {
        tie(dist, a, b) = edge[i];

        if(!Merge(a, b)) continue;


        answer += dist;
        ++cnt;

        if(cnt == v) break;
    }

    cout << answer;

    return 0;
}
