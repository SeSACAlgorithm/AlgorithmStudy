#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n;
const int ROOT = 1; 
int unused = ROOT + 1;
const int MX = 1000 * 15 + 5;
map<string, int> nxt[MX];

void Insert(vector<string>& route)
{
    int cur = ROOT;

    for (string& s : route)
    {
        if(!nxt[cur][s])
            nxt[cur][s] = unused++;
        
        cur = nxt[cur][s];
    }
}


void dfs(int v, int d)
{
    for(auto nx : nxt[v])
    {
        for (int i = 0; i < d; ++i) cout << "--";
        cout << nx.first << '\n';
        dfs(nx.second, d + 1);
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while (n--)
    {
        int k; cin >> k;    
        vector<string> vec(k);

        for(int i = 0; i < k; ++i)
             cin >> vec[i];

        Insert(vec);
    }

    dfs(ROOT, 0);

    return 0;
}
