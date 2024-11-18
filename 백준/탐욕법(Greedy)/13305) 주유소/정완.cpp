#include <iostream>
#include <algorithm>

typedef long long ll;       /*자료형 선언*/

using namespace std;

ll len[100001] = { 0, };
ll price[100001] = { 0, };
ll min_price[100001];

int main()
{
    int N;
    cin >> N;

    for(int i=0; i<N-1; i++)    // 도로 길이
        cin >> len[i];

    for(int i=0; i<N; i++)      // 도시의 기름 값
        cin >> price[i];

    min_price[0] = price[0];    // 최소 가격 스타트 --> 첫 번째 도시

    for(int i=1; i<N; i++)      // 두 번째 도시부터 최소 가격 비교
        min_price[i] = min(min_price[i-1], price[i]);

    long long ans = 0;

    for(int i=0; i<N-1; i++)
        ans += len[i] * min_price[i];

    cout << ans;
}