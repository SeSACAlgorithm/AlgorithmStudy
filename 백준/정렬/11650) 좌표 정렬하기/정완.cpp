#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    vector<pair<int, int>> vec;

    int N;
    cin >> N;
    int x, y;

    for(int i=0; i<N; i++)
    {
        cin >> x >> y;
        vec.push_back({x, y});
    }

    sort(vec.begin(), vec.end());

    for(int i=0; i<N; i++)
        cout << vec[i].first << " " << vec[i].second << "\n";

}
