#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.rbegin(), v.rend());

    long long sum = 0;

    for(int i=0; i<n; i++)
    {
        if(i % 3 != 2)      // 세번째 떨이 제외
            sum += v[i];
    }

    cout << sum;
}