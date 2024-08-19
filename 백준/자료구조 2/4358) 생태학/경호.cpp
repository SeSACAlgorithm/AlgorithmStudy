#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> count;
    int total = 0;
    string temp;
    while(getline(cin, temp))
    {
        ++count[temp];
        ++total;
    }

    cout << fixed;
    cout.precision(4);
    for(auto it = count.begin(); it != count.end(); ++it)
    {
        float rate = (static_cast<float>(it->second) / total);
        cout << it->first << " " << rate * 100 << "\n";
    }
}