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

bool UnionFind(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    if(a == b) return false;
    if(p[a] == p[b]) --p[a];
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}


int main() 
{
    
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e; cin >> v >> e;
    int a, b, distance;

    

    vector<tuple<int, int, int>> edge(e);

    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> distance;
        edge[i] = {distance, a, b};
    }

    sort(edge.begin(), edge.end());

    int answer = 0;
    int cnt = 0;

    for (int i = 0; i < e; ++i)
    {
        tie(distance, a, b) = edge[i];

        if(!UnionFind(a, b)) continue;

        answer += distance; 
        ++cnt;

        if(cnt == v - 1) break;
    }

    cout << answer;


    return 0;
}
