#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Parent[10001];

int GetParent(int x)
{
    if(Parent[x] == x) return x;
    return Parent[x] = GetParent(Parent[x]);
}

void UnionFindParent(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    if(a < b) Parent[b] = a;
    else Parent[a] = b;
}

bool FindSameParent(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    if(a == b) return true;
    return false;
}

class Edge
{
public:
    int node[2];
    int distance;
    
    Edge(int a, int b, int d)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = d;
    }

    bool operator< (Edge& edge)
    {
        return this->distance < edge.distance;
    }
};


int main() 
{
    
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    vector<Edge> vec;

    for (int i = 1; i <= n; ++i)
        Parent[i] = i;

    for (int i = 0; i < m; ++i)
    {
        int a, b, d; cin >> a >> b >> d;
        vec.push_back(Edge(a, b, d));
    }

    sort(vec.begin(), vec.end());


    int answer = 0;

    for (int i = 0; i < vec.size(); ++i)
    {
        if (!FindSameParent(vec[i].node[0], vec[i].node[1]))
        {
            answer += vec[i].distance;
            UnionFindParent(vec[i].node[0], vec[i].node[1]);
        }
    }

    cout << answer;
   


    return 0;
}
