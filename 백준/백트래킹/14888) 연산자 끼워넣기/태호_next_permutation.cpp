#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, mn = 0x7f7f7f7f, mx = -0x7f7f7f7f;

int arr[4];

vector<int> signs(1, 0);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; ++i)
        cin >> numbers[i];

    for(int i = 0; i < 4; ++i)
        cin >> arr[i];

    for (int i = 0; i < 4; ++i)
        while (arr[i]--)
            signs.push_back({i});

    do
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (signs[i] == 0) sum += numbers[i];
            else if (signs[i] == 1) sum -= numbers[i];
            else if (signs[i] == 2) sum *= numbers[i];
            else sum /= numbers[i];
        }

        mn = min(sum, mn);
        mx = max(sum, mx);


    } while(next_permutation(signs.begin() + 1, signs.end()));

    cout << mx << '\n' << mn;
}
