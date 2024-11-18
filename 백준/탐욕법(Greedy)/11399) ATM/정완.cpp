#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum[1001];

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    int total = 0;

    for(int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());   // 정렬

    for(int i=0; i<N; i++)
    {
        if( i != 0)     // 첫번째를 제외 한 나머지 누적 합
            sum[i] = sum[i-1] + v[i];

        else
            sum[i] += v[i];

        total += sum[i];
    }

    cout << total;
}