#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(1001, -1);

int GetParent(int x)
{
    if(p[x] < 0) return x;
    return p[x] = GetParent(p[x]);
}

bool FindSameParent(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);
    
    if(a == b) return false;
    if(p[a] == p[b]) --p[a];
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}

tuple<int, int, int> edge[1000001];

int main() 
{
    
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e = 0; cin >> v;


    for (int i = 1; i <= v; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            int x; cin >> x;
            if(i >= j) continue;

            edge[e++] = { x,i,j };
        }
    }

    sort(edge, edge + e);

    int cnt = 0;
    long long answer = 0;

    for (int i = 0; i < e; ++i)
    {
        int distance, a, b;
        tie(distance, a, b) = edge[i];

        if (!FindSameParent(a, b)) continue;

        ++cnt;
        answer += distance;

        if(cnt == v - 1) break;
    }
  
    cout << answer;


    return 0;
}
