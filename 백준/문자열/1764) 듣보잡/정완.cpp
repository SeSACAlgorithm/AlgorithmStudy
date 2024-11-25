#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    map<string, int> mp;
    vector<string> vs;

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N+M; i++)
    {
        string str;
        cin >> str;

        mp[str]++;

        if(mp[str] >= 2)
            vs.push_back(str);
    }

    sort(vs.begin(), vs.end());

    cout << vs.size() << "\n";

    for(string a : vs)
        cout << a << "\n";
}