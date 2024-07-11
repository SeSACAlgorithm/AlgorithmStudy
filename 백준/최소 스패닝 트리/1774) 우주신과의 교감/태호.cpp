#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<int> p(1001, -1);


int GetParent(int x)
{
    if (p[x] < 0) return x;
    return p[x] = GetParent(p[x]);
}

bool UnionFind(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    if (a == b) return false;
    if (p[a] == p[b]) --p[a];
    if (p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}


tuple<long double, int, int> edge[1000001];
pair<int, int> coord[1001];

int main()
{

    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int a, b, e = 0, cnt = 0;

    double distance;



    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        coord[i] = { a, b };
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;

        if (UnionFind(a, b)) 
            ++cnt;
    }


    for (int i = 1; i <= n; ++i)
    {
        a = coord[i].first, b = coord[i].second;

        for (int j = i + 1; j <= n; ++j)
        {
            distance = pow(a - coord[j].first, 2) + pow(b - coord[j].second, 2);
            edge[e++] = { distance, i, j };
        }
    }

    sort(edge, edge + e);

    
    long double answer = 0.0;

    for (int i = 0; i < e; ++i)
    {
        tie(distance, a, b) = edge[i];

        if (!UnionFind(a, b)) continue;

        answer += sqrt(distance);
        ++cnt;

        if (cnt == n - 1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << answer;

    return 0;
}
