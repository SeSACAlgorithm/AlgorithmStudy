#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[100001];

int main(void) 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
        cout << arr[i].first << ' ' << arr[i].second << '\n';

    return 0;
}
