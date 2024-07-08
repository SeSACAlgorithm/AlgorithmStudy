#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
ios::sync_with_stdio(0);
cin.tie(0);

unordered_map<string, int> M;
int n, k; cin >> n >> k;

for (int i = 0; i < k; ++i)
{
    string str; cin >> str;

    auto elem = M.find(str);

    if (M.end() != elem)
        M.erase(elem);

    M[str] = i;
}

vector<pair<string, int>> sv(M.begin(), M.end());
sort(sv.begin(), sv.end(), [](pair<string, int> a, pair<string, int> b)
    {return a.second < b.second; });

n = min(n, (int)sv.size());

for (int i = 0; i < n; ++i)
    cout << sv[i].first << '\\n';

}
