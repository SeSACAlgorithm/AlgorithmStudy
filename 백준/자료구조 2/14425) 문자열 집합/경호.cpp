#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    string temp;
    map<string, bool> group;
    for(int i = 0; i < N; ++i)
    {
        cin >> temp;
        group[temp] = true;
    }

    int count = 0;
    for(int i = 0; i < M; ++i)
    {
        cin >> temp;
        if (group[temp])
            ++count;
    }

    cout << count;
}