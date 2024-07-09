#include "iostream"
#include "map"
#include "algorithm"

using namespace std;

int main()
{
    pair<string, int> p = {"", -1};
    map<string, int> m;
    string s;
    int n;
    cin >> n;

    while (n--)
    {
        cin >> s;        
        m[s]++;
    }

    for(auto a : m)
        if (a.second > p.second)
            p = a;

    cout << p.first;
}