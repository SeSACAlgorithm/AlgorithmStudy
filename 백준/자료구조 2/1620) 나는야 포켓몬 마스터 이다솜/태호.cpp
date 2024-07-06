#include <bits/stdc++.h>

using namespace std;

string Arrnum[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m; cin >> n >> m;
    unordered_map<string, int> umap;

    for (int i = 1; i <= n; ++i)
    {
        cin >> Arrnum[i];
        umap[Arrnum[i]] = i;
    }

    for (int i = 0; i < m; ++i)
    {
        string k; cin >> k;

        if (isdigit(k[0]))
            cout << Arrnum[stoi(k)] << '\n';
        else
            cout << umap[k] << '\n';


    }

    return 0;
}
