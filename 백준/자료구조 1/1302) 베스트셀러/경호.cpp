#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string temp;
    map<string, int> counts;
    for(int i = 0; i < N; ++i)
    {
        cin >> temp;
        ++counts[temp];
    }

    vector<pair<string, int>> books(counts.begin(), counts.end());
    sort(books.begin(), books.end(), [](pair<string, int> a, pair<string, int> b)
    {
    	return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    cout << books[0].first;
}