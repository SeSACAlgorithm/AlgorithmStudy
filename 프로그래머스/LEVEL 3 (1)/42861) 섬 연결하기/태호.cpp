#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(101, -1);

int find(int x)
{
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool UnionFind(int x, int y)
{
    int u = find(x), v = find(y);
    
    if(u == v) return false;
    if(p[u] == p[v]) --p[u];
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[2] < b[2];
    });
    
    for(int i = 0; i < costs.size(); ++i)
    {
        if(!UnionFind(costs[i][0], costs[i][1])) continue;
        
        answer += costs[i][2];
    }
    
    return answer;
}
