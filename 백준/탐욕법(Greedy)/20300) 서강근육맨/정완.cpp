#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    int N;
    cin >> N;

    ll m[10001];
    ll min = 0;
    
    for(int i=0; i<N; i++)
        cin >> m[i];

    sort(m, m + N);                         // 근손실 정렬

    // 1. 운동 기구가 홀수일 경우
    if(N % 2 == 1)
    {
        min = m[N-1];                       // 마지막 제일 큰 근손실 최소값 시작

        N--;

        for(int i=0; i<N/2; i++)
        {
            ll X = m[i] + m[(N-1) - i];     // 마지막 값 빼고 나머지 최소값, 최대값 합 찾기

            if(X > min)                     // 마지막 값 보다 큰 경우
                min = X;                    // 최소값 업데이트
        }
    }

    // 2. 운동 기구가 짝수일 경우
    else
    {
         for(int i=0; i<N/2; i++)
        {
            ll X = m[i] + m[(N-1) - i];     // 최소값, 최대값 합

            if(X > min)                     // 업데이트 된 값 보다 큰 경우
                min = X;                    // 최소값 업데이트
        }
    }

    cout << min;
}